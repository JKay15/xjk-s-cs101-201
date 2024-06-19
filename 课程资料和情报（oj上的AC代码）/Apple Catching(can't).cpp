// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// #include <cstring>
// #include <unordered_map>
// using namespace std;
// int t, w;
// int dp[1001][31][2];
// vector<int> v;
// int pro(int num, int rest, int pre)
// {
//     if (rest == 0 || num == v.size())
//     {
//         return 0;
//     }
//     if (dp[num][rest][pre] != -1)
//         return dp[num][rest][pre];
//     int tmp = 0;
//     if (pre == 0)
//     {
//         tmp = max(v[num] + pro(num + 1, rest - 1, 0), pro(num + 1, rest, 1));
//     }
//     else
//     {
//         tmp = v[num] + pro(num + 1, rest, 0);
//     }
//     return dp[num][rest][pre] = tmp;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> t >> w;
//     int total = 0;
//     int pre = -1;
//     int first = 0;
//     for (int i = 1; i <= t; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         if (tmp != pre)
//         {
//             if (pre == -1)
//             {
//                 pre = tmp;
//                 total++;
//                 first = tmp;
//             }
//             else
//             {
//                 v.push_back(total);
//                 total = 1;
//                 pre = tmp;
//             }
//         }
//         else
//         {
//             total++;
//         }
//         if (i == t)
//         {
//             v.push_back(total);
//         }
//     }
//     memset(dp, -1, sizeof(dp));
//     cout << pro(0, w, (first == 1) ? 1 : 0) << endl;

//     return 0;
// }

#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int tree1[1005], tree2[1005];
int dp[1005][35];
int T, W;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> W;
    for (int i = 1; i <= T; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
            tree1[i] = 1;
        else
            tree2[i] = 1;
        tree1[i] += tree1[i - 1];
        tree2[i] += tree2[i - 1];
    }
    for (int i = 1; i <= T; i++)
        for (int j = 0; j < i; j++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (w % 2 == 0)
                {
                    dp[i][w] = max(dp[i][w], dp[j][w] + tree1[i] - tree1[j]);
                    if (w + 1 <= W)
                        dp[i][w + 1] = max(dp[i][w + 1], dp[j][w] + tree2[i] - tree2[j]);
                }
                else
                {
                    dp[i][w] = max(dp[i][w], dp[j][w] + tree2[i] - tree2[j]);
                    if (w + 1 <= W)
                        dp[i][w + 1] = max(dp[i][w + 1], dp[j][w] + tree1[i] - tree1[j]);
                }
            }
        }
    int maxn = 0;
    for (int i = 0; i <= W; i++)
        maxn = max(maxn, dp[T][i]);
    cout << maxn << endl;
    return 0;
}