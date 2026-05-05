#include <bits/stdc++.h>

using namespace std;

int sum[10010]={0};

long long power(long long X,long long Y,long long mod_num){
	if(Y==1){return X%mod_num;}
	if(fmod(Y,2)==0){
		return power((X*X)%mod_num,Y/2,mod_num)%mod_num;
	}
	else{
		return ((X%mod_num)*power( (X*X)%mod_num , (Y-1)/2 , mod_num )%mod_num)%mod_num;
	}
}

int main(){
    int n,m,k;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>m>>k;
        for(int j=1;j<=10000;j++){
           sum[j]=(sum[j-1]+power(j,k,10000))%10000;

        }
        cout<<(m/10000*sum[10000]+sum[m%10000])%10000<<endl;
        ans=0;
    }
    return 0;

}
