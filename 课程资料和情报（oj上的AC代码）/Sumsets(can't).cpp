//分奇偶递推！！！
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
int mod = 1000000000;
int dp[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i&1){
            dp[i]=dp[i-1];
        }else{
            dp[i]=dp[i-1]+dp[i/2];
            dp[i]%=mod;
        }
    }
    cout << dp[n] << endl;
}