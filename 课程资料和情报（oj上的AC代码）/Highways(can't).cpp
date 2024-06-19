// 最小支撑树——很明显的图论题，需要积累基础知识，现在肯定做不出来的

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 505;
int n;
int graph[maxn][maxn];
int dis[maxn];
int vis[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        memset(dis, INF, sizeof(dis));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }
        int ans = 0;
        int mind;
        int pos = 0;
        vis[0] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && graph[pos][j])
                {
                    dis[j] = min(dis[j], graph[pos][j]);
                }
            }
            mind = INF;
            pos = -1;
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && dis[j] < mind)
                {
                    mind = dis[j];
                    pos = j;
                }
            }
            vis[pos] = 1;
            ans = max(ans, mind);
        }
        cout << ans << endl;
    }

    return 0;
}