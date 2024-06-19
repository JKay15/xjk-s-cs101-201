//没想到怎么贪心，但是dp肯定是可以的，在n<1000的时候选择o(n^2)肯定是可以接受的
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n;
int dp[maxn][2];
int num[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        dp[i][0]=dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(num[i]==num[j])continue;
            else if(num[i]<num[j]){
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
            }else{
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans;
    return 0;
}
//提供一个贪心的做法:只需要所有波峰波谷就好了
