#include <bits/stdc++.h>
using namespace std;

int max(long long n,long long m){
	return (n>=m)?n:m;
}



long long func(long long n,long long m,long long k){
	for(long long i=0;i<k;i++){
		if(n<=0) break;
		else{
			n=n & max(n-m,0);
		}
	}
	return n;
	
}



int main(){
	long long n;cin>>n;
	for(long long i=0;i<n;i++){
		long long x,y,z;cin>>x>>y>>z;
		cout<<func(x,y,z)<<endl;
		
	}
	return 0;
}
