#include<bits/stdc++.h>
using namespace std;


int find2(int n){
	int size,temp,count=0;
	int num[7]={0};
	for(int i=0;;i++){
		if(n>=pow(10.0,i) && n<=pow(10.0,i+1)) {size=i+1;break;}
	}
	for(double i=0;i<=size;i++){							//分离位数（倒序）
		temp=(n%(int)(pow(10.0,i+1)))/(int)pow(10.0,i);
		num[(int)i]=temp;										
		n=n-temp*pow(10.0,i);
	}
	for(int i=0;i<size;i++){
		if(num[i]==2) count++;
	}
	return count;
}

int main(){
	int l,r,sum=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		sum+=find2(i);
	}
	cout<<sum;
	return 0;
	
}
