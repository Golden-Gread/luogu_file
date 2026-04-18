#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,t;
	cin>>a>>b>>c>>d;
	t=c*60+d-(a*60+b);
	cout<<t/60<<" "<<t%60;
	return 0;
}
