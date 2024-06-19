//有启发性的动态规划，保证了递推公式中出现的dp项不会跨越被删除的点
#include <bits/stdc++.h>
using namespace std;
int n, p, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> p >> m && n)
    {
        int first = 1;
        for (int i = n; i >= 1; i--)
        {
            int res = (m - 1) % i;
            for (int j = i + 1; j <= n; j++)
            {
                res = (res + m) % j;
            }
            res = (res + p) % n;
            if (res == 0)
            {
                res = n;
            }
            if (first)
            {
                cout << res;
                first = 0;
            }
            else
            {
                cout << "," << res;
            }
        }
        cout << endl;
    }

    return 0;
}