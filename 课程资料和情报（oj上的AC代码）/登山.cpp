#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dp[maxn],dp1[maxn],n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
        dp[i]=dp1[i]=1;
    }
    for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)if(h[j]<h[i])dp[i]=max(dp[i],1+dp[j]);
    for(int i=n-2;i>=0;i--)
    for(int j=n-1;j>i;j--)if(h[j]<h[i])dp1[i]=max(dp1[i],1+dp1[j]);
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,dp[i]+dp1[i]-1);
    cout<<ans;
    return 0;
}