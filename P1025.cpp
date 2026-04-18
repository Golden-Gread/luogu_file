#include<bits/stdc++.h>
using namespace std;


int func(int n,int m){
	if(n==0 or m==1){return 1;}
	else if(n<m){return func(n,n);}
	else{return func(n,m-1)+func(n-m,m);}
}



int main(){
	int n,m;cin>>n>>m;
	cout<<func(n-m,m);
	
} 
