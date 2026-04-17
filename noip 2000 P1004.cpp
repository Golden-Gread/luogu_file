#include <bits/stdc++.h>
using namespace std;

int num[12][12]={0};
int dp[15][15][3]={0};
int visited[15][15][2]={0};

int main(){
	int n;cin>>n;int x=-1,y=-1,val=-1;cin>>x>>y>>val;
	while(!(x==0 and y==0 and val==0)){
		num[x+1][y+1]=val;cin>>x>>y>>val;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1]);
			dp[i][j][1]+=num[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j][2]=max(dp[i-1][j][2],dp[i][j-1][2]);
			dp[i][j][2]+=num[i][j];
		}
	}
	
	
	cout<<dp[n][n][1]+dp[n][n][2];
	
	
	return 0;
}
