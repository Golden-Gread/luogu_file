#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

queue<int> q;


void PrintTree(TreeNode* root){
    if(root==nullptr) return ;
    q.push(root->val);
    if(root->left!=nullptr) PrintTree(root->left);
    if(root->right!=nullptr) PrintTree(root->right);
}

void PrintTree1(TreeNode* root){
	if(root==nullptr) return ;
	if(root->left!=nullptr) PrintTree1(root->left);
	q.push(root->val);
	if(root->right!=nullptr) PrintTree1(root->right);
	
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<treeNodeToString(root)<<endl;
    PrintTree(root);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
	PrintTree1(root);
	
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
    return 0;
}
