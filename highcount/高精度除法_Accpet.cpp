#include<bits/stdc++.h>
using namespace std;


bool compare(std::string s1,std::string s2){
	return (s1.length()!=s2.length())?s1.length()>s2.length():s1>=s2;
}

string func_jian(string s1,string s2){
	int a[25000]={0},b[25000]={0},c[25000]={0};string result="";
	if(s1.length()<s2.length() || (s1.length()==s2.length()&&s1<s2)){swap(s1,s2);result+="-";}
	int len=s1.length();
	for(int i=s1.length()-1;i>=0;i--){a[s1.length()-i-1]=s1[i]-'0';}
	for(int i=s2.length()-1;i>=0;i--){b[s2.length()-i-1]=s2[i]-'0';}
	for(int i=0;i<s1.length();i++){int temp=a[i]-b[i];if(temp<0){a[i+1]--;c[i]+=temp+10;}else{c[i]+=temp;}}
	while(c[len-1]==0 and len!=1){len--;}
	for(int i=len-1;i>=0;i--){result+=c[i]+'0';}
	return result;
}

pair<string,string> func_chu(string s1,string s2){
	string ans="",temp="";
	for(int i=0;i<s1.length();i++){
		temp+=s1[i];
		if(compare(temp,s2)){
			int counter=0;
			while(compare(temp,s2)){
				temp=func_jian(temp,s2);counter++;
			}
			ans+=counter+'0';
			
		}
		else{
			ans+="0";
		}
		temp=(temp=="0")?"":temp;
	}
	
	
	string res="";bool b=1;
	for(int i=0;i<ans.length();i++){
		if(ans[i]=='0' and b and i!=ans.length()-1){
		}
		else{
			res+=ans[i];b=0;
		}
	}
	return make_pair(res,temp);
}

int main(){
	string s1,s2;cin>>s1>>s2;
	cout<<func_chu(s1,s2).first;
	
} 
