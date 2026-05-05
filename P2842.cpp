#include <bits/stdc++.h>
using namespace std;


int value[10003]={0},cost[1000003]={0};
int n,w;


int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>value[i];
	}
	for(int i=1;i<=10015;i++) cost[i]=1000000;
	for(int i=1;i<=n;i++){
		for(int j=value[i];j<=w;j++){
			cost[j]=min(cost[j],cost[j-value[i]]+1);
		}
	}
	
	cout<<cost[w];
	
	
	return 0;
}
