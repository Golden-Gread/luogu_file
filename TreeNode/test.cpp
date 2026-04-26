#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="00000/";
    s=s.substr(s.find_first_not_of('0'),s.length());
	s=(s=="")?"0":s;
	
    cout<<s<<endl;
    
    return 0;
}
