#include <bits/stdc++.h>
using namespace std;

int dp[120][120][120][120]={0};
int num[355]={0},card[5]={0};


int main(){
	int m,n;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i+1];
	}
	for(int i=0;i<m;i++){
		int x;cin>>x;
		card[x]++;
	}
	for(int a=0;a<=card[1];a++){
		for(int b=0;b<=card[2];b++){
			for(int c=0;c<=card[3];c++){
				for(int d=0;d<=card[4];d++){
					int step=1+a*1+b*2+c*3+d*4;
					if(a>0){dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+num[step]);}
					if(b>0){dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+num[step]);}
					if(c>0){dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+num[step]);}
					if(d>0){dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+num[step]);}
				}
			}
		}
	}
	
	cout<<dp[card[1]][card[2]][card[3]][card[4]]+num[1];
	
	
	return 0;
}
