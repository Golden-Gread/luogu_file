#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

typedef pair<int,int> p;

int main(){
    int n,m,s;
    cin>>n>>m>>s;
    
    map<p,long long> graph;
        

    for(int i=1;i<=n;i++)
        graph[p(i,i)]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[p(u,v)]=w;
        graph[p(v,u)]=w;
    }

    for (int k = 1; k <= n; ++k) {          
        for (int i = 1; i <= n; ++i) {      
            for (int j = 1; j <= n; ++j) {  
                if (graph.find(p(i,j)) != graph.end() && graph.find(p(i,k)) != graph.end() && graph.find(p(k,j)) != graph.end()) {
                    if (graph[p(i,k)] + graph[p(k,j)] < graph[p(i,j)]) {
                        graph[p(i,j)] = graph[p(i,k)] + graph[p(k,j)];
                    }
                }
            }
        }
    }

    

    
    for(int i=1;i<=n;i++){
       cout<<graph[p(s,i)]<<" ";
    }

    return 0;

}