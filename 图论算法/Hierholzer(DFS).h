#include<bits/stdc++.h>

void hierholzer_dfs(int node,std::unordered_map<int, std::vector<int>> &g, std::vector<int> &path){
    while(!g[node].empty()){
        int next=g[node].back();
        g[node].pop_back();
        hierholzer_dfs(next,g,path);
    }
    path.push_back(node);
}


std::vector<int> hierholzer(std::unordered_map<int, std::vector<int>> &graph, int str_node,std::unordered_map<int, int> in_degree,std::unordered_map<int, int> out_degree){
    using namespace std;
    vector<int> path;


}

