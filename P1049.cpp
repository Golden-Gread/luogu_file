#include<bits/stdc++.h>
using namespace std;

int dp[32][20004]={0};
int vl[32]={0};


int main(){
	int n,m;cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>vl[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j>=vl[i]){dp[i][j]=max(dp[i-1][j],dp[i-1][j-vl[i]]+vl[i]);}
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	cout<<m-dp[n][m];
	
	
} 
