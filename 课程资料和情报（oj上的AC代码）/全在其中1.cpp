#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>s>>t){
        int l1=s.length(),l2=t.length(),l=0,r=0;
        while(l<l1&&r<l2){
            while(r<l2&&t[r]!=s[l])r++;
            if(r<l2&&l<l1&&t[r]==s[l]){l++;r++;}
        }
        cout<<((l1==l)?"Yes":"No")<<"\n";
    }
    return 0;
}