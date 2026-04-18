#include<bits/stdc++.h>
using namespace std;
int main(){
	int is,afs,nmax=-1,maxd;
	for(int i=1;i<=7;i++){
		cin>>is>>afs;
		if(is+afs>nmax) {nmax=is+afs;maxd=i;}
		
		
	}
	
	cout<<maxd;
	
	return 0;
	
}
