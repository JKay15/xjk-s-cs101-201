#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int maxn = 105;
#define inf 0x3f3f3f3f
int m, n;
int p[maxn];
int l[maxn];
int dp[maxn];
vector<pair<int, int>> rep[maxn];
pair<int, int> level_range;
int vis[maxn];
int dfs(int num, int total)
{
    if (num >= n + 1)
    {
        return total;
    }
    if (dp[num])
    {
        return dp[num] + total;
    }
    int tmp = total + p[num];
    for (pair goods : rep[num])
    {
        if (l[goods.first] >= level_range.first && l[goods.first] <= level_range.second && !vis[goods.first])
        {
            pair level(level_range.first, level_range.second);
            level_range.first = max(l[goods.first] - m, level_range.first);
            level_range.second = min(l[goods.first] + m, level_range.second);
            vis[goods.first] = 1;
            tmp = min(tmp, dfs(goods.first, total + goods.second));
            vis[goods.first] = 0;
            level_range = level;
        }
    }
    dp[num] = tmp - total;
    return tmp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        cin >> l[i];
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            rep[i].push_back(pair(tmp1, tmp2));
        }
    }
    level_range = pair(l[1] - m, l[1] + m);
    vis[1] = 1;
    cout << dfs(1, 0);
    return 0;
}