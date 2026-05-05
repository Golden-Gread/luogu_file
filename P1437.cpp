#include <bits/stdc++.h>

using namespace std;

int dp[52][52][1253]={0};
int maxn[52][52][1253];
int n,m;
int num[52][52],num1[52][52],num2[52][52];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cin>>num[i][j];
        }
    }
    memset(maxn,-1,sizeof(maxn));


    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            num2[i][j]=num[j][n-i+1],num1[i][j]=num1[i][j-1]+num2[i][j];

    for(int i=0;i<=m;i++)
        maxn[0][0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=i;j>=0;j--){
            for(int k=j;k<=m;k++){
                if(maxn[i-1][max(0,j-1)][k-j]>=0){
                    dp[i][j][k]=maxn[i-1][max(0,j-1)][k-j]+num1[i][j];
                    maxn[i][j][k]=max(maxn[i][j-1][k],dp[i][j][k]);
                }
            }
        }
    }


    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ans=max(ans,dp[i][j][m]);
        }
    }

    cout<<ans<<endl;
    return 0;

}