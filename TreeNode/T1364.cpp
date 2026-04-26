#include<bits/stdc++.h>
using namespace std;
struct Tree{
    char val;
	string s="";
    Tree* left;
    Tree* right;
    Tree():left(nullptr),right(nullptr){};
    Tree(char c):val(c),left(nullptr),right(nullptr){};
};

//queue<char> q={};
Tree* tree_root=nullptr;
queue<char> q_temp={};

void printTree(Tree* root){
    if(root==nullptr){return;}
	if((root->val>='A' and root->val<='Z') or (root->val>='a' and root->val<='z')){
		q_temp.push(root->val);
	}
    if(root->left!=nullptr){printTree(root->left);}
    if(root->right!=nullptr){printTree(root->right);}
}

Tree* res=nullptr;

bool is_in(char c,string s){
    for(char x:s){if(x==c){return true;}}
    return false;
}

void finding(Tree* root,char c){
    if(root==nullptr){return;}
    if(is_in(c,root->s)){
        res=root;
		return;
    }
    if(root->left!=nullptr) finding(root->left,c);
    if(root->right!=nullptr) finding(root->right,c);
}

int main(){
    string s1,s2;cin>>s1>>s2;
    tree_root=new Tree(s2[0]);tree_root->s=s1;
	
    for(int i=0;i<s2.length();i++){
		finding(tree_root,s2[i]);int pos=res->s.find(s2[i]);res->val=s2[i];
		res->left=new Tree();
		res->right=new Tree();
		res->left->s=res->s.substr(0,pos);
		res->right->s=res->s.substr(pos+1);
		res->s.clear();
		res=nullptr;
		
    }
	
    
	

	
    //buildTree(tree_root,s1.substr(0,pos),true);
    //buildTree(tree_root,s1.substr(pos+1),false);
    printTree(tree_root);
	while(!q_temp.empty()){
		cout<<q_temp.front();q_temp.pop();
	}
	
    return 0;
    
}
