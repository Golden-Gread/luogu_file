#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char num[130][130]={0};
int visited[130][130]={0};
int visited1[130][130]={0};
int n,m,sx=1,sy=1,ex=1,ey=1;
map<p,p> father;

void mark(int x,int y){
	for(int i=x;i<=m and num[x][i]!='X';i++){visited1[x][i]=-1;}
	for(int i=x;i>0 and num[x][i]!='X';i--){visited1[x][i]=-1;}
	for(int i=y;i<=n and num[i][y]!='X';i++){visited1[i][y]=-1;}
	for(int i=y;i>0 and num[i][y]!='X';i--){visited1[i][y]=-1;}
	for(int i=x,j=y;i<=m and j>0 and num[i][j]!='X';i++,j--){visited1[i][j]=-1;}
	for(int i=x,j=y;i>0 and j<=n and num[i][j]!='X';i--,j++){visited1[i][j]=-1;}
	for(int i=x,j=y;i<=m and j<=n and num[i][j]!='X';i++,j++){visited1[i][j]=-1;}
	for(int i=x,j=y;i>0 and j>0 and num[i][j]!='X';i--,j--){visited1[i][j]=-1;}
}



int path_length(p ep){
	int len=1;p it=father[ep];
	while(!(it.first==sx and it.second==sy)){
		len++;it=father[it];
	}
	return len;
}

void bfs(int x,int y){
	queue<p> q;q.push(make_pair(x,y));
	visited[x][y]=1;
	while(!q.empty()){
		p it=q.front();q.pop();
		
		if(visited1[it.first][it.second]==-1){
			cout<<path_length(it)<<endl;
			return ;
		}
		
		for(int i=0;i<4;i++){
			int nx=it.first+dx[i],ny=it.second+dy[i];
			bool b=(nx>0 and nx<=n) and (ny>0 and ny<=m);
			if(b and visited[nx][ny]==0 and num[nx][ny]!='X'){
				q.push(make_pair(nx,ny));
				visited[nx][ny]=1;
				father[q.back()]=it;
			}
		}
	}
	
	cout<<"Poor Harry"<<endl;
}



int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			num[i][j]=s[j-1];
		}
	}
	
	cin>>ex>>ey>>sx>>sy;
	while(!(sx==0 and sy==0 and ex==0 and ey==0)){
		mark(ex,ey);
		bfs(sx,sy);
		for(int i=0;i<130;i++){
			memset(visited[i],0,130);
			memset(visited1[i],0,130);
			
		}
		cin>>ex>>ey>>sx>>sy;
	}
	
} 
