#include<bits/stdc++.h>
using namespace std;
pair<int,int> func_c(int num1,int num2){
	int count=0;
	while(num1>=num2){num1-=num2;count++;}
	return make_pair(count,num1);
}
int main(){
	string num_s,result="";int num2;cin>>num_s>>num2;
	int temp=0;
	for(int i=0;i<num_s.length();i++){
		temp=temp*10+num_s[i]-'0';auto result_pair=func_c(temp,num2);
		result+=result_pair.first+'0';temp=result_pair.second;}
	int len=0;
	while(result[len]=='0' and len<result.length()-1){len++;}
	cout<<result.substr(len)<<endl<<temp;
	return 0;
}
