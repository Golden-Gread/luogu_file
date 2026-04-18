#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,m=0,t=0,sum=0;
	double heart=10,x;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x>>a;
		if(heart-x>0){
			sum+=a;
			heart-=x;
			if(heart>10) heart=10;
		}
		else break;
	}
	
	while(sum>=pow(2.0,m)){
		m++;sum-=pow(2.0,m-1);
		
	}
	t=sum;
	
	cout<<m<<" "<<t;
	
	
}
