#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> p;//  (distance,node)

unordered_map<int,priority_queue<int,vector<int>,greater<int>>> g; 
unordered_map<int,int> indeg; 
unordered_map<int,int> outdeg; 
vector<int> path; 



void hierholzer_dfs(int node){
    while(!g[node].empty()){
        int next=g[node].top();
        g[node].pop();
        hierholzer_dfs(next);
    }
    path.push_back(node);
}




int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        g[u].push(v);
        outdeg[u]++;
        indeg[v]++;
    }

    for(int i=1;i<=n;i++){
        int diffr = outdeg[i]-indeg[i];

        if(abs(diffr) > 1){
            is_possible = 0;
            break;
        }
        if(diffr==1){
            if(start!=-1) is_possible=0;
            start = i;
        }
        if(diffr==-1){
            if(end!=-1){
                is_possible=0;
            }
            end=i;
        }
    }

    if(is_possible==0){
        cout<<"No"<<endl;
        return 0;
    }

    if(start == -1){  
        for(int i = 1; i <= n; i++){
            if(outdeg[i] > 0){
                start = i;
                break;
            }
        }
        if(start == -1){
            cout << "No" << endl;  
            return 0;
        }
    }

    hierholzer_dfs(start);

    if(path.size() != m + 1){
        cout << "No" << endl;
        return 0;
    }
    
    reverse(path.begin(), path.end());

    for(auto x : path){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}