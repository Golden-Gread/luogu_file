#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,m;cin>>n>>m;
	vector<int> maps(n+1,0);
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		int sum=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='P') sum+=(1<<(s.length()-i-1));
		}
		maps[i]=sum;
	}
	
	
	return 0;
}
