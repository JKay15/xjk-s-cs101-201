//二进制优化，用得少，但是想到了要用还是不错
#include <bits/stdc++.h>
using namespace std;
int cash, N;
vector<int> n;
vector<int> D;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> cash >> N)
    {
        n.clear();
        D.clear();
        dp.clear();
        n.resize(N + 5);
        D.resize(N + 5);
        dp.resize(cash + 5);
        for (int i = 1; i <= N; i++)
        {
            cin >> n[i] >> D[i];
        }
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int k = 1;
            for (; k <= n[i]; k <<= 1)
            {
                int top = k * D[i];
                for (int j = cash; j >= top; j--)
                {
                    if (dp[j - top])
                    {
                        dp[j] = 1;
                        ans = max(ans, j);
                    }
                }
                n[i] -= k;
            }
            if (n[i])
            {
                int top = n[i] * D[i];
                for (int j = cash; j >= top; j--)
                {
                    if (dp[j - top])
                    {
                        dp[j] = 1;
                        ans = max(ans, j);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}