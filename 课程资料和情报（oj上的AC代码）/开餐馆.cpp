#include <bits/stdc++.h>
using namespace std;
int n,k;
int dp[105][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n>>k;
        vector<int> m(n+1),p(n+1);
        for(int i=1;i<=n;i++)cin>>m[i];
        for(int i=1;i<=n;i++)cin>>p[i];
        dp[1][1]=p[1];
        for(int i=2;i<=n;i++){
            dp[i][1]=p[i];
            for(int j=i-1;j>=1;j--){
                if(m[i]-m[j]>k)dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+p[i]);
                dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1]));
            }
        }
        cout<<max(dp[n][1],dp[n][0])<<"\n";
    }
    return 0;
}