//要和最长公共子序列联系起来，但是我没敢想，所以就爆内存了
//答案就是最长公共子序列的长度与总长度的差，这个其实会去想，但是不敢想，因为一下证不出
//感觉我的这个递推是更直觉的，但是POJ加强了数据，所以过不了——也是可以滚动的，只是当时脑子确实傻了，得恢复一段时间
#include <bits/stdc++.h>
using namespace std;
int n,dp[2][5001];
string tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>tmp;
    memset(dp,127,sizeof(dp));
    int t=0;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
        if(tmp[i]==tmp[j]){
            if(j-i>1)dp[t][j]=min((i+2==j)?0:dp[t^1][j-1],1+min(dp[t^1][j],dp[t][j-1]));
            else dp[t][j]=0;
        }
        else dp[t][j]=1+min((i+1==j)?0:dp[t^1][j],(i+1==j)?0:dp[t][j-1]);
        }
        t^=1;
    }
    cout<<dp[n%2][n-1];
    return 0;
}
// #include<iostream>
// using namespace std;
// #define N 5010
// char s1[N],s2[N];
// int d[2][N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >>n;
//     cin>>(s1+1);
//     for(int i=1;i<=n;i++)s2[i]=s1[n-i+1];
//     int ans=0;
//     int t=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(s1[i]==s2[j])d[t][j] = d[t^1][j-1]+1;
//             else d[t][j]=max(d[t^1][j],d[t][j-1]);
//             ans=max(ans,d[t][j]);
//         }
//         t^=1;
//     }
//     cout<<n-ans;
//     return 0;
// }