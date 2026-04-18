#include<bits/stdc++.h>
using namespace std;
int main(){
	int l,m,sta,end;
	int tree[10006]={0};
	cin>>l>>m;
	for(int i=0;i<m;i++){
		cin>>sta>>end;
		for(int k=sta;k<=end;k++){
			tree[k]=1;
		}
		
	}
	int sum=0;
	
	for(int i=0;i<=l;i++){
		if(tree[i]==0) sum++;
		
	}
	
	cout<<sum;
	return 0;
	
}
