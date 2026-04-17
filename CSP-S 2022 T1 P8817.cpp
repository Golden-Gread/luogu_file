#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m,k;
int graph[10004][10004]={0};
ll value[10004]={0};
int visited[10004]={0};

void bfs(int ind){
	queue<int> q;q.push(ind);
	visited[ind]=1;
	while(!q.empty()){
		auto it=q.front();q.pop();
		
		for(int i=1;i<sizeof(graph[it]);i++){
			if()
		}
	}
}



int main(){
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>value[i];
	}
	for(int i=0;i<m;i++){
		int s1,s2;cin>>s1>>s2;
		graph[s1][s2]=1;graph[s2][s1]=1;
	}
	
	
	
	return 0;
}
