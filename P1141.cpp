//Accpet

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;


int num[1005][1005]={0};
int ans[1005*1005]={0};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m;
int visited[1005][1005]={0};




int bfs(int x,int y,int area_id){
	
	queue<p> q;q.push(make_pair(x,y));
	visited[x][y]=area_id;
	int sum=1;
	
	while(!q.empty()){
		auto it=q.front();q.pop();
		
		int temp=(num[it.first][it.second]==0)?1:0;
		
		for(int i=0;i<4;i++){
			int nx=it.first+dx[i],ny=it.second+dy[i];
			
			if((nx>0 and nx<=n) and (ny>0 and ny<=n) and num[nx][ny]==temp and visited[nx][ny]==0){
				sum++;
				q.push(make_pair(nx,ny));
				visited[nx][ny]=area_id;
			}
		}
	}
	
	return sum;
}



int main(){
	
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		char s[1005];scanf("%s",s);
		for(int j=1;j<=n;j++){
			num[i][j]=s[j-1]-'0';
		}
	}
	int c_id=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(visited[i][j]==0){
				ans[c_id]=bfs(i,j,c_id);
				c_id++;
				
			}
		}
	}
	
	
	
	
	for(int i=0;i<m;i++){
		int x,y;scanf("%d %d",&x,&y);
		cout<<ans[visited[x][y]]<<endl;
	}
	return 0;
}
