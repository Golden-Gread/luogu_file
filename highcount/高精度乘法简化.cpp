#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[250]={0},b[250]={0},c[550]={0};
	string s1,s2;cin>>s1>>s2;
	for(int i=s1.length()-1;i>=0;i--){a[s1.length()-i-1]=s1[i]-'0';}
	for(int i=s2.length()-1;i>=0;i--){b[s2.length()-i-1]=s2[i]-'0';}
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			c[i+j]+=a[i]*b[j];
			if(c[i+j]>=10){c[i+j+1]+=c[i+j]/10;c[i+j]%=10;}}}
	int len=s1.length()+s2.length();
	while(len>0 and c[len]==0){len--;};
	for(int i=len;i>=0;i--){cout<<c[i];}
}
