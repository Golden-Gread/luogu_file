#include <bits/stdc++.h>
using namespace std;
int dp[35][35]={0};
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1 or j==1){dp[i][j]=1;continue;}
			if(i%2==0 and j%2==0){dp[i][j]=0;continue;}
			else{dp[i][j]=dp[i-1][j]+dp[i][j-1];}
		}
	}
	cout<<dp[n][m];
	
	return 0;
}
