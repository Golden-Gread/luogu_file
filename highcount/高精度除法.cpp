#include<bits/stdc++.h>
using namespace std;
vector<string> x_num_list={};
bool compare(string s1,string s2){return (s1.length()!=s2.length())?s1.length()>s2.length():s1>=s2;}
bool compare1(string s1,string s2){return (s1.length()!=s2.length())?s1.length()>s2.length():s1>s2;}
string func_x(string s1,string s2){
	int a[250000]={0},b[250000]={0},c[550000]={0};
	for(int i=s1.length()-1;i>=0;i--){a[s1.length()-i-1]=s1[i]-'0';}
	for(int i=s2.length()-1;i>=0;i--){b[s2.length()-i-1]=s2[i]-'0';}
	for(int i=0;i<s1.length();i++){for(int j=0;j<s2.length();j++){c[i+j]+=a[i]*b[j];if(c[i+j]>=10){c[i+j+1]+=c[i+j]/10;c[i+j]%=10;}}}
	int len=s1.length()+s2.length();
	while(len>0 and c[len]==0){len--;};string result="";
	for(int i=len;i>=0;i--){result+=c[i]+'0';}
	return result;
}
int find(string s1,string s2){for(int i=0;i<=9;i++){if(compare(s1,x_num_list[i]) and compare1(x_num_list[i+1],s1)){return i;}}}
string func_jian(string s1,string s2){
	int a[250000]={0},b[250000]={0},c[250000]={0};string result="";
	if(s1.length()<s2.length() || (s1.length()==s2.length()&&s1<s2)){swap(s1,s2);result+="-";}
	int len=s1.length();
	for(int i=s1.length()-1;i>=0;i--){a[s1.length()-i-1]=s1[i]-'0';}
	for(int i=s2.length()-1;i>=0;i--){b[s2.length()-i-1]=s2[i]-'0';}
	for(int i=0;i<s1.length();i++){int temp=a[i]-b[i];if(temp<0){a[i+1]--;c[i]+=temp+10;}else{c[i]+=temp;}}
	while(c[len-1]==0 and len!=1){len--;}
	for(int i=len-1;i>=0;i--){result+=c[i]+'0';}
	return result;
}
int main(){
	string s1,s2,result="";cin>>s1>>s2;int len=s1.length();
	for(int i=0;i<=10;i++){x_num_list.push_back(func_x(s2,to_string(i)));}
	int num[2000003]={0};
	for(int i=0;i<len;i++){num[i]=s1[i]-'0';}
	string temp=to_string(num[0]);
	for(int i=1;i<len;i++){
		int num_temp=find(temp,s2);result+=num_temp+'0';
		temp=func_jian(temp,x_num_list[num_temp]);
		temp=(temp=="0")?"":temp;
		temp+=num[i]+'0';
	}
	int num_temp=find(temp,s2);result+=num_temp+'0';
	temp=func_jian(temp,x_num_list[num_temp]);len=0;
	while(result[len]=='0' and len<result.length()-1){len++;}
	cout<<result.substr(len);
	
	return 0;
	
}
