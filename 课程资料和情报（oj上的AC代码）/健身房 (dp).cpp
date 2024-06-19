#include <bits/stdc++.h>
using namespace std;
int T,n,t[1005],w[1005],dp[1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin>>T>>n;
    for(int i=1;i<=n;i++)cin>>t[i]>>w[i];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    for(int j=T;j>0;j--)if(j>=t[i]&&dp[j-t[i]]!=-1)dp[j]=max(((dp[j]==-1)?0:dp[j]),w[i]+dp[j-t[i]]);
    cout<<dp[T];
    return 0;
}