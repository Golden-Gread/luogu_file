#include<bits/stdc++.h>
using namespace std;

bool find(int arr[],int n,int size){
	for(int i=0;i<size;i++){
		if(arr[i]==n) return true;
		
	}
	return false;
}


int main(){
	int num[1003]={0};
	int num1[1003]={0};
	int ind=0,n;
	cin>>n;
	ind=n-1;
	
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	
	
	for(int i=0;i<ind;i++){
		num1[i]=abs(num[i]-num[i+1]);
	}
	for(int i=1;i<ind;i++){
		if(!find(num1,i,n)) {cout<<"Not jolly";return 0;}
		
	}
	cout<<"Jolly";
	return 0;
	
	
}
