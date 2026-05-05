#include<bits/stdc++.h>

using namespace std;


int n,m=0,ans=0;

int main(){
    vector<int> arr;
    while(cin>>n){
        arr.push_back(n);m+=1;
    }

    vector<int> dp(m,1),d;
    for(int i=0;i<arr.size();i++){
        auto it = upper_bound(dp.begin(),dp.end(),arr[i],greater<int>());
        if(it==dp.end()){
            d.push_back(arr[i]);
        }
        else{
            *it=arr[i];
        }
    }

    cout<<d.size()<<endl;

    ans=0;fill(dp.begin(),dp.end(),1);
    vector<int> d1;
    for(int i=0;i<arr.size();i++){
        auto it = lower_bound(dp.begin(),dp.end(),arr[i],greater<int>());
        if(it==dp.end()){
            d.push_back(arr[i]);
        }
        else{
            *it=arr[i];
        }
    }

    cout<<d1.size()<<endl;

    cout<<ans<<endl;
    return 0;

}