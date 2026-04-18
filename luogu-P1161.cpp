#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	double a;
	
	int num[2000004]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>t;
		for(int k=1;k<=t;k++){
			num[(int)floor(a*k)]=!(num[(int)floor(a*k)]);
		}
	}
	
	for(int i=1;;i++){
		if(num[i]==1) {cout<<i;return 0;
		}
	}
}
