#include <bits/stdc++.h>
using namespace std;
int n,p;
bool check(){
    if(!(p%19))return 1;
    string tmp=to_string(p),tar="19";
    if(tmp.find(tar)!=string::npos)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    while(n--){
        cin>>p;
        cout<<((check())?"Yes":"No")<<"\n";
    }
    return 0;
}