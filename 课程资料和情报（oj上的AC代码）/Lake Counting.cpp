#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
const int maxn = 105;
int n, m;
char field[maxn][maxn];
int pond[maxn][maxn];
int total;
#define check(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y)
{
    if (!check(x, y))
        return;
    for (int i = 0; i < 8; i++)
    {
        if (check(x + dx[i], y + dy[i]) && field[x + dx[i]][y + dy[i]] == 'W' && !pond[x + dx[i]][y + dy[i]])
        {
            pond[x + dx[i]][y + dy[i]] = total;
            dfs(x + dx[i], y + dy[i]);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> field[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (field[i][j] == 'W' && !pond[i][j])
            {
                total++;
                pond[i][j] = total;
                dfs(i, j);
            }
        }
    }
    cout << total << endl;

    return 0;
}