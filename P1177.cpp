#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;cin>>n;
	vector<int> l={};
	for(int i=0;i<n;i++){
		int x;cin>>x;
		l.push_back(x);
		
	}
	sort(l.begin(),l.end());
	for(int i:l){
		cout<<i<<" ";
	}
	return 0;
}
