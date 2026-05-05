#include <bits/stdc++.h>
using namespace std;


long long dp[10008]={0};


int main(){
	int n,w;cin>>n>>w;
	vector<int> a(n);
	dp[0]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=w;i++){
		for(int j=0;j<n;j++){
			if(i-a[j]>=0){
				dp[i]=(dp[i]+dp[i-a[j]])%1000000007;
			}
		}
	}

	cout<<dp[w]<<endl;
	
	return 0;
}
