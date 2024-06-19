#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int t, m;
int w[105];
int v[105];
int dp[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= t; i++)
    {
        dp[i] = (i >= w[1]) ? v[1] : 0;
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = t; j >= 1; j--)
        {
            if(j-w[i]>=0){
                dp[j]= max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[t] << endl;

    return 0;
}