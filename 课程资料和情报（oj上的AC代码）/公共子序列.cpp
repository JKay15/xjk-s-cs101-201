#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;
int dp[205][205];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp1, tmp2;
    while (cin >> tmp1 >> tmp2)
    {
        int l1 = tmp1.length();
        int l2 = tmp2.length();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                if (tmp1[i] == tmp2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        cout << dp[l1][l2] << endl;
    }

    return 0;
}