#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	bool b=false;
	for(int i=10000;i<=30000;i++){
		int x=i;
		string num=to_string(x);
		
		int k1,k2,k3;
		k1 = stoi(num.substr(0, 3));  // 前三位
		k2 = stoi(num.substr(1, 3));  // 中间三位
		k3 = stoi(num.substr(2, 3));  // 后三位
		if(k1%k==0 && k2%k==0 && k3%k==0){
			cout<<i<<endl;
			b=true;
		}
	}
	if(!b) cout<<"No";
	
	return 0;
}
