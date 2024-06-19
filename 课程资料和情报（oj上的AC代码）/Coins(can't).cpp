//一维的dp就够了，没必要二维

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// #include <cstring>
// #include <unordered_map>
// using namespace std;
// int n, m;
// vector<int> A;
// vector<int> C;
// int prices[100001];
// int dp[101][100001];
// int dfs(int num, int total)
// {
//     if (num == n)
//     {
//         if (total > m || total == 0)
//             return 0;
//         if (prices[total]==0)
//         {
//             prices[total]=1;
//             return 1;
//         }
//         return 0;
//     }
//     if (total > m)
//         return 0;
//     if(dp[num][total]!=-1)return 0;
//     int tmp = 0;
//     for (int i = 0; i <= C[num]; i++)
//     {
//         if (total + i * A[num] <= m)
//         {
//             tmp += dfs(num + 1, total + i * A[num]);
//         }
//     }
//     return dp[num][total]=tmp;
// }
// void solve()
// {
//     A.clear();
//     C.clear();
//     memset(prices,0,sizeof(prices));
//     memset(dp,-1,sizeof(dp));
//     for (int i = 0; i < n; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         A.push_back(tmp);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int tmp;
//         cin >> tmp;
//         C.push_back(tmp);
//     }
//     cout << dfs(0, 0) << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while (cin >> n >> m && n && m)
//     {
//         solve();
//     }

//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10; 

int v[maxn], w[maxn], dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && n && m)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
        }

        memset(dp, -1, sizeof(dp)); 
        dp[0] = 0; 

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++) 
            {
                if (dp[j] >= 0)  
                    dp[j] = w[i];
                else if (j < v[i] || dp[j - v[i]] <= 0)
                {
                    dp[j] = -1;
                }

                else
                { 
                    dp[j] = dp[j - v[i]] - 1;
                }
            }
        }
        int sum = 0;                
        for (int i = 1; i <= m; i++) 
        {
            if (dp[i] >= 0) 
                sum++;
        }
        cout << sum << endl;
    }
    return 0;
}