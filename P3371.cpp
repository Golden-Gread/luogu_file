#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p; //(distance,node)


const int INT=1e9;

vector<ll> dij(vector<vector<p>> &graph, int str_node){
    int n=graph.size();
    vector<ll> dist(n,INT);
    dist[str_node]=0;

    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,str_node});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        if(dist[it.second]<it.first) continue;
        
        for(auto it_1:graph[it.second]){
            int dis=it_1.first;
            int node=it_1.second;

            if(dist[node]>dist[it.second]+dis){
                dist[node]=dist[it.second]+dis;
                pq.push({dist[node],node});
            }
        }
    }

    return dist;

}



int main(){
    int n,m,s;

    cin>>n>>m>>s;

    vector<vector<p>> graph(n+1);
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        auto res=find(graph[u].begin(),graph[u].end(),p(w,v));
        if(res==graph[u].end()){
            graph[u].push_back(make_pair(w,v));
        }
        else{
            int index=distance(graph[u].begin(),res);
            graph[u][index].first=max(graph[u][index].first,w);
        }
    }

    vector<ll> dist=dij(graph,s);

    for(int i=1;i<dist.size();i++){
       if(dist[i]!=INT){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<INT_MAX<<" ";
        }
    }

    return 0;
}