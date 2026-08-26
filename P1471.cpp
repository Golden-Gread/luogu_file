#include <bits/stdc++.h>
using namespace std;
typedef long double db;
const int N=1e5+10;

struct Node{
	db add,mul,tem=0;
}tree[N*4+4];

vector<db> Data(N);

void buildTree(int l,int r,int nc){
	if(l==r){
		tree[nc].add=Data[l];
		tree[nc].mul=pow(Data[l],2);
		return;
	}
	int mid=(l+r)>>1;
	buildTree(l,mid,nc<<1);
	buildTree(mid+1,r,nc<<1|1);
	tree[nc].add=tree[nc<<1].add+tree[nc<<1|1].add;
	tree[nc].mul=tree[nc<<1].mul+tree[nc<<1|1].mul;
}

void update(int l,int r,db val,int nc){
	tree[nc].mul+=2*val*tree[nc].add+(r-l+1)*val*val;
	tree[nc].add+=val*(r-l+1);
	tree[nc].tem+=val;
}

void pushDown(int l,int r,int nc){
	if(tree[nc].tem==0) return;
	int mid=(l+r)>>1;
	update(l,mid,tree[nc].tem,nc<<1);
	update(mid+1,r,tree[nc].tem,nc<<1|1);
	tree[nc].tem=0;
}

void rangeChange(int l,int r,int L,int R,int nc,db val){
	if(l<=L and R<=r){
		update(L,R,val,nc);
		return ;
	}
	
	pushDown(L,R,nc);
	int mid=(L+R)>>1;
	if(l<=mid) rangeChange(l,r,L,mid,nc<<1,val);
	if(r>mid) rangeChange(l,r,mid+1,R,nc<<1|1,val);
	tree[nc].add=tree[nc<<1].add+tree[nc<<1|1].add;
	tree[nc].mul=tree[nc<<1].mul+tree[nc<<1|1].mul;
}

db getSum_add(int l,int r,int L,int R,int nc){
	if(l>R or r<L){
		return 0;
	}
	if(l<=L and R<=r){
		return tree[nc].add;
	}
	
	int mid=(L+R)>>1;
	pushDown(L,R,nc);
	db ans=0;
	if(l<=mid) ans+=getSum_add(l,r,L,mid,nc<<1);
	if(r>mid) ans+=getSum_add(l,r,mid+1,R,nc<<1|1);
	return ans;
}


db getSum_mul(int l,int r,int L,int R,int nc){
	if(l>R or r<L){
		return 0;
	}
	if(l<=L and R<=r){
		return tree[nc].mul;
	}
	
	int mid=(L+R)>>1;
	pushDown(L,R,nc);
	db ans=0;
	if(l<=mid) ans+=getSum_mul(l,r,L,mid,nc<<1);
	if(r>mid) ans+=getSum_mul(l,r,mid+1,R,nc<<1|1);
	return ans;
}

int main(){
	cout<<fixed<<setprecision(4);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>Data[i];
	}
	
	buildTree(1,n,1);
	
	for(int i=1;i<=m;i++){
		int op;cin>>op;
		if(op==1){
			db x,y,k;cin>>x>>y>>k;
			rangeChange(x,y,1,n,1,k);
		}
		if(op==2){
			db x,y;cin>>x>>y;
			cout<<getSum_add(x,y,1,n,1)/(y-x+1)<<"\n";
		}
		if(op==3){
			db x,y;cin>>x>>y;
			cout<<getSum_mul(x,y,1,n,1)/(y-x+1)-pow(getSum_add(x,y,1,n,1)/(y-x+1),2)<<"\n";
		}
	}
	
	return 0;
}
