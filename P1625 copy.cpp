#include <bits/stdc++.h>
using namespace std;

bool compare(std::string s1,std::string s2){
	return (s1.length()!=s2.length())?s1.length()>s2.length():s1>=s2;
}

std::string func_x(std::string s1,std::string s2){
	int a[250000]={0},b[250000]={0},c[550000]={0};
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
	ans+='/';
	ans=ans.substr(ans.find_first_not_of('0'),ans.length());
	if(ans=="/"){ans="0";}
	else{ans.pop_back();}

	return make_pair(ans,temp);
}

string func_1(int n,int m){
	string ans="1";
	for(int i=n;i<=m;i++){
		ans=func_x(ans,to_string(i));
	}
	return ans;
	
}

string func_2(string n,string m){
	return func_jian(n,func_x(func_chu(n,m).first,m));
}


int main(){
	int n,m;cin>>n>>m;
	
	string P,F,X,Y,x1,y1;

    string temp=func_1(1,n+m-1);
    
	x1=X=func_jian(func_chu(temp,func_1(1,m-1)).first,func_1(1,n));
	y1=Y=func_x(to_string(m-1),temp);
	
	string r=func_2(X,Y);
	
	while(r!="0"){
		X=Y;
		Y=r;
		r=func_2(X,Y);
	}
	//cout<<func_chu(x1,Y).first<<endl<<func_chu(y1,Y).first;

	printf("%s\n%s\n",func_chu(x1,Y).first.c_str(),func_chu(y1,Y).first.c_str());

	return 0;
}