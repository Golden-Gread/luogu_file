#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,nmax=-1000002,x;
	long long sum=0;
	
	int num[105]={0};
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>nmax){nmax=x;}
		
		num[i]=x;
		
		
	}
	
	for(int i=0;i<n;i++){
		if(num[i]==nmax){}
		else sum+=num[i];
		
	}
	
	cout<<sum;
	return 0;
	
}
