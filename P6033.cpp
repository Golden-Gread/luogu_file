#include<bits/stdc++.h>
using namespace std;

vector<int> num(1000000000000,0);
set<long long> s;

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        s.insert(x);
    }
    long long ans=0;
    
    for(long long x=1;x<=1000000000000;x++){
        if(num[x]==0){continue;}
        ans+=num[x]/2*2*x;
        num[x]-=num[x]/2*2;
        num[2*x]+=num[x]/2;
        if(num[x]==0){
            s.erase(x);
        }
        else{

        }
    }

    cout<<ans<<endl;

    return 0;
}