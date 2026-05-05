#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n,m,d;
    cin>>n>>m>>d;

    if(m<n*(d+1)){
        cout<<-1<<endl;
        return 0;
    }
    else if(m<=n*(d+2)){
        cout<<m-n*(d+1)<<endl;
        return 0;
    }
    else{
        cout<<((m-n*(d+2))/(d+1))+n<<endl;
    }


}