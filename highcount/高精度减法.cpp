#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;cin>>s1>>s2;//bool is_under_zero=0;
	int a[250]={0},b[250]={0},c[250]={0},len=s1.length();
	if(s1.length()<s2.length() || (s1.length()==s2.length()&&s1<s2)){swap(s1,s2);cout<<"-";}
	for(int i=s1.length()-1;i>=0;i--){a[s1.length()-i-1]=s1[i]-'0';}
	for(int i=s2.length()-1;i>=0;i--){b[s2.length()-i-1]=s2[i]-'0';}
	for(int i=0;i<s1.length();i++){
		int temp=a[i]-b[i];
		if(temp<0){a[i+1]--;c[i]+=temp+10;}else{c[i]+=temp;}
	}
	while(c[len-1]==0 and len!=1){len--;}
	for(int i=len-1;i>=0;i--){cout<<c[i];}
	return 0;
}
