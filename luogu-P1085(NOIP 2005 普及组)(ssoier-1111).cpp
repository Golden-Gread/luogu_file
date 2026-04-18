#include<bits/stdc++.h>
using namespace std;
int main(){
	int is,afs,nmax=0,maxd;
	bool b=true;
	for(int i=1;i<=7;i++){
		cin>>is>>afs;
		if(is+afs>nmax && is+afs>8) {nmax=is+afs;maxd=i;b=false;}
		
		
	}
	
	if(!b) cout<<maxd;
	else cout<<0;
	
	
	return 0;
	
}
