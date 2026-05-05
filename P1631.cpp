#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    priority_queue<int,vector<int>,greater<int>> q;
    q.push(a[0]+b[0]);
    for(int i=1;i<n;i++){
        q.push(a[0]+b[i]);
        q.push(a[i]+b[0]);
    }

    for(int i=0;i<n;i++){
        cout<<q.top()<<" ";
        q.pop();
    }

    return 0;
}