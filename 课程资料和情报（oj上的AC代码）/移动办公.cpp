#include <bits/stdc++.h>
using namespace std;
int t,m,p[105],n[105],dp[105][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t>>m;
    for(int i=1;i<=t;i++)cin>>p[i]>>n[i];
    dp[1][0]=p[1];dp[1][1]=n[1];
    for(int i=2;i<=t;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]-m)+p[i];
        dp[i][1]=max(dp[i-1][0]-m,dp[i-1][1])+n[i];
    }
    cout<<max(dp[t][0],dp[t][1]);
    return 0;
}