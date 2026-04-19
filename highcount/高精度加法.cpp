#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,result="";cin>>s1>>s2;
	auto s1_begin=s1.begin(),s2_begin=s2.begin(),s1_end=s1.end(),s2_end=s2.end();
	int temp=0;
	
	for(auto it1=s1_end-1,it2=s2_end-1;it1!=s1_begin-1 and it2!=s2_begin-1;it1--,it2--){
		int s1_it=*it1-'0',s2_it=*it2-'0';
		if(s1_it+s2_it+temp>=10){
			result+=(s1_it+s2_it+temp)-10+'0';
			temp=1;	
		}
		else{
			result+=(s1_it+s2_it+temp)+'0';
			temp=0;
		}
	}
	if(s1.length()!=s2.length()){
		for(int i=abs((int)s1.length()-(int)s2.length())-1;i>=0;i--){
			int temp1=(s1.length()>s2.length())?s1[i]-'0'+temp:s2[i]-'0'+temp;
			if(temp1>=10){
				temp=1;
				result+=temp1-10+'0';
			}
			else{
				result+=temp1+'0';
				temp=0;
			}
		}
		if(temp==1){
			result+='1';}
	}
	else if(temp==1){
		result+='1';	
	}
	reverse(result.begin(),result.end());
	cout<<result;
	return 0;
	
}
