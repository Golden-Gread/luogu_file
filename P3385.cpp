#include<bits/stdc++.h>

const int INF=INT_MAX;
using namespace std;

typedef pair<int, int> pii;

int n,m;

void print_path(int start,vector<int> &path){
    if(path[start]==-1){
        cout<<start<<endl;
        return ;
    }
    else{
        print_path(path[start],path);
    }
}

bool SPFA(vector<vector<pii>> &graph,vector<int> &path,vector<int> &dist,int start){
    
    dist.assign(n,INF);
    vector<bool> in_queue(n,false);
    vector<int> count(n,0);
    path.assign(n,-1);
    dist[start]=0;

    queue<int> q;
    q.push(start);
    in_queue[start]=true;
    count[start]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        in_queue[u]=false;

        for(auto p:graph[u]){
            int v=p.first;
            int w=p.second;
            if(dist[u]!= INF and dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                path[v]=u;


                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v]=true;
                    count[v]++;

                    if(count[v]>n){
                        return 0;
                    }
                }

            }
        }
    }

    return 1;
}

int main(){
    int c;cin>>c;
    for(int i=0;i<c;i++){
        cin>>n>>m;
        vector<vector<pii>> graph(n);
        
        for(int j=0;j<m;j++){
            int u,v,w;cin>>u>>v>>w;
            if(w>=0){graph[u].push_back(pii(v,w));
            graph[v].push_back(pii(u,w));}
            else{
                graph[u].push_back(pii(v,w));
            }
        }
        vector<int> path,dist;
        cout<<(SPFA(graph,path,dist,0)?"NO":"YES")<<endl;
    }
    return 0;
}