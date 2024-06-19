//floyd算法思想：贪心
//dfs写失败了，原因是什么
//dfs在处理终止条件时，出现问题：
//只在遍历完了才停止，或者没有边可走了才停止
//返回值，在遍历完了的情况下，返回time是合理的，但是没边可走了，还返回time，就不太好了，需要返回INF
//图上的深搜很麻烦，没有范式的话，大概率写出来是很不好的
//接下来解释一下floyd算法的原理

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int graph[105][105];
int main()
{
    int n;
    while (cin >> n && n)
    {
        memset(graph, INF, sizeof(graph));
        for (int i = 1; i <= n; i++)
        {
            graph[i][i] = 0;
            int t;
            cin >> t;
            while (t--)
            {
                int tmp1, tmp2;
                cin >> tmp1 >> tmp2;
                graph[i][tmp1] = tmp2;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (k == i || k == j || j == i)
                        continue;
                    graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
                }
            }
        }
        int mmin = INF;
        int mmax;
        int start = 0;
        for (int i = 1; i <= n; i++)
        {
            mmax = 0;
            for (int j = 1; j <= n; j++)
            {
                mmax = max(graph[i][j], mmax);
            }
            if (mmin > mmax)
            {
                mmin = mmax;
                start = i;
            }
        }
        if (mmin == INF)
        {
            cout << "disjoint" << endl;
        }
        else
        {
            cout << start  << " " << mmin << endl;
        }
    }
}