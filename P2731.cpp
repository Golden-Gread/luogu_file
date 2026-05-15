#include<bits/stdc++.h>
using namespace std;

stack<int> path;
int d[503]={0};

int n,m,nmax=-1,nmin=1000;

void dfs(int start,vector<vector<int>>& G){
    for(int i=1;i<=nmax;i++){
        if(G[start][i]){
            G[start][i]--;
            G[i][start]--;
            dfs(i,G);
        }
    }
    path.push(start);
}

int main(){
    cin>>m;
    vector<vector<int>> G(501,vector<int>(501,0));
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u][v]++;
        G[v][u]++;
        d[u]++;
        d[v]++;
        nmax=max(nmax,max(u,v));
        nmin=min(nmin,min(u,v));
    }

    int stp=nmin;
    for(int i=1;i<=500;i++){
        if(d[i]%2==1){
            stp=i;break;
        }
    }

    dfs(stp,G);

    while(!path.empty()){
        cout<<path.top()<<endl;
        path.pop();
    }

    return 0;
}