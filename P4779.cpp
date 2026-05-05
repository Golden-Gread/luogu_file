#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

int main(){
    int n,m,s;
    cin>>n>>m>>s;
    
    vector<vector<int>> graph(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)
        graph[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }

    for (int k = 1; k <= n; ++k) {          
        for (int i = 1; i <= n; ++i) {      
            for (int j = 1; j <= n; ++j) {  
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<graph[s][i]<<" ";
    }

    return 0;

}