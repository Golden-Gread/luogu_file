#include <bits/stdc++.h>
using namespace std;

struct sta{
	vector<int> data={};
}s;

void push(){
	int x;cin>>x;
	s.data.push_back(x);
}

void pop(){
	if(!s.data.empty()){
		s.data.pop_back();return ;
	}
	cout<<"Empty"<<endl;
}

void query(){
	if(!s.data.empty()){
		cout<<s.data.back()<<endl;return;
		
	}
	cout<<"Anguei!"<<endl;
	
}



int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int m;cin>>m;
		for(int j=0;j<m;j++){
			string type;cin>>type;
			if(type=="push"){push();}
			else if()
		}
	}
	
	
	
	return 0;
}
