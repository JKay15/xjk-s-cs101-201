#include <bits/stdc++.h>
using namespace std;
int n,r,c;
int tri[105][105],dp[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n&&n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)cin>>tri[i][j];
        cin>>r>>c;
        for(int i=n;i>=r;i--){
            for(int j=i;j>=1;j--){
                if(i==n)dp[j]=tri[i][j];
                else dp[j]=max(tri[i][j],max(dp[j],dp[j+1]));
            }
        }
        cout<<dp[c]<<"\n";
    }
    return 0;
}