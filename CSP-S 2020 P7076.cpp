#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> rule;



int main(){
	ull n,m,c,k;
	cin>>n>>m>>c>>k;
	
	vector<ull> animals(n);
	ull existsed_bits=0;
	for(int i=0;i<n;i++){
		cin>>animals[i];
		existsed_bits |= animals[i];
	}
	
	vector<rule> rules(m);
	for(int i=0;i<m;i++){
		cin>>rules[i].first>>rules[i].second;
	}
	
	vector<bool> foods(c+1,false);
	for(auto it:rules){
		if(existsed_bits >> it.first & 1){
			foods[it.first]=1;
		}
	}
	
	ull temp=0;
	
	for(auto it:rules){
		if(foods[it.second]==0){
			temp |= (1ULL << it.first);
		}
	}
	
	int zero_num=__builtin_popcountll(temp);
	
	
	uint64_t total_ok;
	if (k - zero_num == 64) {
		total_ok = UINT64_MAX;  
		total_ok = 0;  
	} else {
		total_ok = 1ULL << (k - zero_num);
	}
	
	
	uint64_t already_ok = 0;
	for (auto x : animals) {
		if ((x & temp) == 0) {
			already_ok++;
		}
	}
	
	uint64_t answer = total_ok - already_ok;
	cout << answer << endl;
	
	
	
	return 0;
}
