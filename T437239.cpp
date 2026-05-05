#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> point;

double dist(point a,point b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

const double INF=1e18;


int main(){
    int n;
    cin>>n;
    vector<point> p(n);
    vector<vector<double>> graph(n+1,vector<double>(n+1,INF));
    for(int i=1;i<=n;i++){
        cin>>p[i-1].first>>p[i-1].second;
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;double w=dist(p[u-1],p[v-1]);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    
    int sp,ep;cin>>sp>>ep;

     for (int k = 1; k <= n; ++k) {          
        for (int i = 1; i <= n; ++i) {      
            for (int j = 1; j <= n; ++j) {  
                if (graph[i][k] != 0 && graph[k][j] != 0) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    cout<<fixed<<setprecision(2)<<graph[sp][ep]<<endl;
    return 0;
}
