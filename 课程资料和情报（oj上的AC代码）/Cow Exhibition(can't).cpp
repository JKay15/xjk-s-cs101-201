//想到了处理负数要+100000，但是没想到要用背包的方法处理，总是希望在dp数组中包含TS和TF的信息，导致数组大小超出内存大小
//但是实际上完全可以枚举TS或者TF的大小，dp数组存下来另一者的大小，这个设计就很棒
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;
int ans=-INF,dp[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> S(n+1),F(n+1);
    for(int i=1;i<=n;i++)cin>>S[i]>>F[i];
    for(int i=0;i<=200000;i++)dp[i]=-INF;
    dp[100000]=0;
    for(int i=1;i<=n;i++){
        if(S[i]<0&&F[i]<0)continue;
        if(S[i]>0){
            for(int j=200000;j>=S[i];j--)if(dp[j-S[i]]>-INF)dp[j]=max(dp[j],dp[j-S[i]]+F[i]);
        }else{
            for(int j=S[i];j<=S[i]+200000;j++)if(dp[j-S[i]]>-INF)dp[j]=max(dp[j],dp[j-S[i]]+F[i]);
        }
    }
    for(int i=100000;i<=200000;i++)ans=((dp[i]>=0)?max(ans,dp[i]+i-100000):ans);
    cout<<ans;
    return 0;
}