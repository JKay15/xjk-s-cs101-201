#include <bits/stdc++.h>
using namespace std;
const int maxn=17;
int n,dp[1<<15][maxn],ttime[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>ttime[i][j];
    memset(dp,127,sizeof(dp));
    dp[1][1]
    for(int i=1;i<(1<<(n-1));i++)
    for(int j=1;j<=n;j++)
        if(dp[i][j]<(1<<30))
            for(int k=1;k<n;k++)
                if(!(i&(1<<(k-1))))
                    dp[i+(1<<(k-1))][k]=min(dp[i+(1<<(k-1))][k],dp[i][j]+ttime[j][k]);
    int ans=(1<<30);
    for(int i=1;i<n;i++)ans=min(ans,dp[(1<<(n-1))-1][i]+ttime[i][n]);
    cout<<ans<<"\n";
    return 0;
}