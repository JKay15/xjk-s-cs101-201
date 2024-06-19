#include <bits/stdc++.h>
using namespace std;
int n,a[10005],b[10005],c[10005],dp[10005][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    dp[1][0]=a[1];
    dp[1][2]=b[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][2],dp[i-1][3])+a[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+b[i];
        dp[i][2]=max(dp[i-1][2],dp[i-1][3])+b[i];
        dp[i][3]=max(dp[i-1][0],dp[i-1][1])+c[i];
    }
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}
//不知道为啥这样写是错的
// #include <bits/stdc++.h>
// using namespace std;
// int n,a[10005],b[10005],c[10005],dp[10005][2];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)cin>>b[i];
//     for(int i=1;i<=n;i++)cin>>c[i];
//     dp[1][0]=a[1];
//     dp[1][1]=b[1];
//     for(int i=2;i<n;i++){
//         dp[i][0]=max(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
//         dp[i][1]=max(dp[i-1][0]+c[i],dp[i-1][1]+b[i]);
//     }
//     cout<<max(dp[n-1][0]+b[n],dp[n-1][1]+a[n]);
//     return 0;
// }