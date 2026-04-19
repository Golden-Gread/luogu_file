#include <bits/stdc++.h>
using namespace std;

bool compare(std::string s1,std::string s2){
	return (s1.length()!=s2.length())?s1.length()>s2.length():s1>=s2;
}

bool compare1(std::string s1,std::string s2){
	return (s1.length()!=s2.length())?s1.length()>s2.length():s1>s2;
}


std::string func_x(std::string s1,std::string s2){
	int a[40000]={0},b[40000]={0},c[80000]={0};
	for(int i=s1.length()-1;i>=0;i--){
		a[s1.length()-i-1]=s1[i]-'0';
	}
	for(int i=s2.length()-1;i>=0;i--){
		b[s2.length()-i-1]=s2[i]-'0';
	}
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			c[i+j]+=a[i]*b[j];
			if(c[i+j]>=10){
				c[i+j+1]+=c[i+j]/10;
				c[i+j]%=10;}
		}
	}
	int len=s1.length()+s2.length();
	while(len>0 and c[len]==0){
		len--;
	}
	std::string result="";
	for(int i=len;i>=0;i--){
		result+=c[i]+'0';
	}
	return result;
}


int find(std::string s1,std::string s2,std::vector<std::string>& x_num_list){
	for(int i=0;i<=9;i++){
		if(compare(s1,x_num_list[i]) and compare1(x_num_list[i+1],s1)){
			return i;}
	}
}


std::string func_jian(std::string s1,std::string s2){
	int a[40000]={0},b[40000]={0},c[40000]={0};
	std::string result="";
	if(s1.length()<s2.length() || (s1.length()==s2.length()&&s1<s2)){
		swap(s1,s2);result+="-";
	}
	int len=s1.length();
	for(int i=s1.length()-1;i>=0;i--){
		a[s1.length()-i-1]=s1[i]-'0';
	}
	for(int i=s2.length()-1;i>=0;i--){
		b[s2.length()-i-1]=s2[i]-'0';
	}
	for(int i=0;i<s1.length();i++){
		int temp=a[i]-b[i];
		if(temp<0){a[i+1]--;
			c[i]+=temp+10;
		}
		else{c[i]+=temp;
		}
	}
	while(c[len-1]==0 and len!=1){
		len--;
	}
	for(int i=len-1;i>=0;i--){
		result+=c[i]+'0';
	}
	return result;
}

std::string func_jia(std::string s1,std::string s2){
	std::string result="";
	int a[40000]={0},b[40000]={0},c[40004]={0};
	for(int i=s1.length()-1;i>=0;i--){
		a[s1.length()-i-1]=s1[i]-'0';
	}
	for(int i=s2.length()-1;i>=0;i--){
		b[s2.length()-i-1]=s2[i]-'0';
	}
	for(int i=0;i<std::max((int)s1.length(),(int)s2.length());i++){
		c[i]+=a[i]+b[i];
		if(c[i]>=10){
			a[i+1]++;c[i]-=10;
		}
	}
	int len=std::max((int)s1.length(),(int)s2.length());
	while(c[len]==0 and len>=1){
		len--;
	}
	for(int i=len;i>=0;i--){
		result+=c[i]+'0';
	}
	return result;
}



std::string func_chu(std::string s1,std::string s2,int point_num){
	std::vector<std::string> x_num_list={};
	std::string result="";
	int len=s1.length();
	for(int i=0;i<=10;i++){
		x_num_list.push_back(func_x(s2,std::to_string(i)));
	}
	int num[40005]={0};
	for(int i=0;i<len;i++){
		num[i]=s1[i]-'0';
	}
	std::string temp=std::to_string(num[0]);
	for(int i=1;i<len;i++){
		int num_temp=find(temp,s2,x_num_list);result+=num_temp+'0';
		temp=func_jian(temp,x_num_list[num_temp]);temp=(temp=="0")?"":temp;temp+=num[i]+'0';
	}
	int num_temp=find(temp,s2,x_num_list);
	result+=num_temp+'0';
	temp=func_jian(temp,x_num_list[num_temp]);
	len=0;
	while(result[len]=='0' and len<result.length()-1){
		len++;
	}
	result=result.substr(len)+".";
	len=s1.length();
	std::string result_point="";
	temp+=num[len]+'0';
	for(int i=len;i<=len+point_num-1;i++){
		int num_temp=find(temp,s2,x_num_list);result_point+=num_temp+'0';
		temp=func_jian(temp,x_num_list[num_temp]);
		temp=(temp=="0")?"":temp;
		temp+=num[i]+'0';
	}
	num_temp=find(temp,s2,x_num_list);
	result_point+=num_temp+'0';
	temp=func_jian(temp,x_num_list[num_temp]);
	len=0;
	if(*(result_point.end()-1)>='5' and temp!="0"){
		result_point=func_jia(result_point.substr(0,result_point.length()-1),"1");
	}
	else{
		result_point[result_point.length()-1]='\0';
	}
	return result+result_point;
}

string func_1(int n,int m){
	string ans="1";
	for(int i=n;i<=m;i++){
		ans=func_x(ans,to_string(i));
	}
	return ans;
	
}

string func_2(string n,string m){
	return func_jian(n,func_x(func_chu(n,m,0),m));
}


int main(){
	int n,m;cin>>n>>m;
	
	string P,F,P_1,F_1;
	
	P_1=P=func_chu(func_1(1,n+m-1),func_1(1,n),0);
	F_1=F=func_1(1,m-1);
	
	string ans;
	
	string r=func_2(P,F);
	
	while(r!="0"){
		P=F;
		F=r;
		r=func_2(P,F);
	}
	
	cout<<func_chu(P_1,F,0)<<endl<<func_chu(F_1,F,0);
	
	
	
	
	return 0;
}
