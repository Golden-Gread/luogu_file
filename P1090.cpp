#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        q.push(x);
    }
    int ans=0;
    while(q.size()>1){
        int x=q.top();q.pop();
        int x1=q.top();q.pop();
        ans+=x+x1;
        q.push(x+x1);
    }


    cout<<ans<<endl;

    return 0;
}