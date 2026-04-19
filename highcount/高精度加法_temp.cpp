#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,result="";cin>>s1>>s2;
	int a[2000]={0},b[2000]={0},c[2002]={0};
	for(int i=s1.length()-1;i>=0;i--){
		a[s1.length()-i-1]=s1[i]-'0';
	}
	for(int i=s2.length()-1;i>=0;i--){
		b[s2.length()-i-1]=s2[i]-'0';
	}
	for(int i=0;i<max((int)s1.length(),(int)s2.length());i++){
		c[i]+=a[i]+b[i];
		if(c[i]>=10){a[i+1]++;c[i]-=10;}
	}
	int len=max((int)s1.length(),(int)s2.length());
	while(c[len]==0 and len>=1){len--;}
	for(int i=len;i>=0;i--){cout<<c[i];}
	return 0;
}
