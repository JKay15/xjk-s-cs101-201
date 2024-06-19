#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int t, m;
vector<int> w;
vector<int> v;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> t;
    v.resize(m+5);
    w.resize(m+5);
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    dp.resize(m+5);
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