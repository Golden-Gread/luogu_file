#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    vector<TreeNode*> children={};
    TreeNode(int x): val(x) {}
    TreeNode(): val(0) {}

};

queue<int> q;


void PrintNode(TreeNode* root){
    if(root==nullptr) return ;
    q.push(root->val);
    for(TreeNode* it : root->children){
        TreeNode* node=it;
        if(node!=nullptr) PrintNode(node); 
    }
}



int main(){
    TreeNode* root=new TreeNode();
    
}