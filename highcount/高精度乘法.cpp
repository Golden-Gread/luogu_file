#include<bits/stdc++.h>
using namespace std;
string addition(string s1,string s2){
	auto s1_begin=s1.begin(),s2_begin=s2.begin(),s1_end=s1.end(),s2_end=s2.end();
	int temp=0;string result="";
	for(auto it1=s1_end-1,it2=s2_end-1;it1!=s1_begin-1 and it2!=s2_begin-1;it1--,it2--){
		int s1_it=*it1-'0',s2_it=*it2-'0';
		if(s1_it+s2_it+temp>=10){result+=(s1_it+s2_it+temp)-10+'0';temp=1;}
		else{result+=(s1_it+s2_it+temp)+'0';temp=0;}}
	if(s1.length()!=s2.length()){
		for(int i=abs((int)s1.length()-(int)s2.length())-1;i>=0;i--){
			int temp1=(s1.length()>s2.length())?s1[i]-'0'+temp:s2[i]-'0'+temp;
			if(temp1>=10){temp=1;result+=temp1-10+'0';}
			else{result+=temp1+'0';temp=0;}}
		if(temp==1){result+='1';}}
	else if(temp==1){result+='1';}
	reverse(result.begin(),result.end());
	return result;
}
string putting_chars(char c,int num){
	string temp="";
	for(int i=0;i<num;i++){temp+=c;}
	return temp;
}
int main(){
	string s1,s2;vector<string> temp_list={};cin>>s1>>s2;
	if(s1.length()<s2.length()){swap(s1,s2);}
	for(int i=s2.length()-1;i>=0;i--){
		string temp_string="";int s2_num=s2[i]-'0';int temp=0;
		for(int j=s1.length()-1;j>=0;j--){
			int num=(s1[j]-'0')*s2_num+temp;
			if(num>=10){temp=num/10;temp_string+=(num%10)+'0';}
			else{temp=0;temp_string+=num+'0';}
		}
		if(temp>0) temp_string+=temp+'0';
		reverse(temp_string.begin(),temp_string.end());temp_list.push_back(temp_string);
	}
	if(temp_list.begin()+1==temp_list.end()){
		string result=temp_list[0],result_temp=result;
		if(result=="0") {cout<<result;return 0;}
		for(int i=0;i<result.length();i++){
			if(result[i]=='0'){result_temp.erase(i,1);}
			else{break;}
		}
		cout<<result_temp;
		return 0;	
	}
	string sum="0";
	for(int i=0;i<s2.length();i++){
		sum=addition(sum,temp_list[i]+putting_chars('0',i));
	}
	cout<<sum;
	return 0;
}
