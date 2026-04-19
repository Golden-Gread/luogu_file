#include <bits/stdc++.h>
using namespace std;


int main(){
	long long n;cin>>n;
	for(long long i=0;i<n;i++){
		long long x,y,z;cin>>x>>y>>z;
		long long mod=x%z;
		if(mod==0){
			cout<<((y>=1)?0:n)<<endl;
		}
		else{
			long long step=z-mod;
			if(y>=step+1){cout<<0<<endl;}
			else{cout<<mod<<endl;}
		}
	}
	
	return 0;
}
