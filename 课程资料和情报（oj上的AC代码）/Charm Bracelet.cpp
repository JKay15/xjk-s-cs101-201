#include <bits/stdc++.h>
using namespace std;
int dp[12885],n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> w(n+1),v(n+1);
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(j>=w[i]){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}