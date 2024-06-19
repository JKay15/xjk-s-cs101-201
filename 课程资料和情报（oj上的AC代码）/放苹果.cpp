#include <bits/stdc++.h>
using namespace std;
int f[15][15];
int dp(int m,int n){
    if(m<n)return dp(m,m);
    if(m==0)return 1;
    if(n==0)return 0;
    if(f[m][n])return f[m][n];
    return dp(m-n,n)+dp(m,n-1);
}
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cout<<dp(m,n)<<"\n";
    }
    return 0;
}