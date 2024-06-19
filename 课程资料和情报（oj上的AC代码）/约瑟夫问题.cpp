#include <bits/stdc++.h>
using namespace std;
int n,m;
int f(int n,int m){
    if(m==1)return n;
    if(n==1)return 1;
    return ((f(n-1,m)-1)+m)%n+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m&&n)cout<<f(n,m)<<"\n";
    return 0;
}