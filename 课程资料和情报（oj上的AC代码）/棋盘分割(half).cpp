//看了ppt，对于其中的递归四个分支不一定能想到
//同时四舍五入也没人家写的这么简练
//对于方差的简化也很好
#include <bits/stdc++.h>
using namespace std;
int n;
int board[9][9], sum[9][9];
int res[15][9][9][9][9];
int ssum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int pro(int x1, int y1, int x2, int y2, int n)
{
    if (res[n][x1][y1][x2][y2] != -1)
        return res[n][x1][y1][x2][y2];
    if (n == 1)
    {
        int tmp = ssum(x1, y1, x2, y2);
        return res[n][x1][y1][x2][y2] = tmp * tmp;
    }
    int ans = 0x7777777;
    for (int i = x1; i < x2; i++)
    {
        int tmp1 = ssum(i + 1, y1, x2, y2);
        int tmp2 = ssum(x1, y1, i, y2);
        ans = min(ans, min(pro(x1, y1, i, y2, n - 1) + tmp1 * tmp1, pro(i + 1, y1, x2, y2, n - 1) + tmp2 * tmp2));
    }
    for (int i = y1; i < y2; i++)
    {
        int tmp1 = ssum(x1, i + 1, x2, y2);
        int tmp2 = ssum(x1, y1, x2, i);
        ans = min(ans, min(pro(x1, y1, x2, i, n - 1) + tmp1 * tmp1, pro(x1, i + 1, x2, y2, n - 1) + tmp2 * tmp2));
    }
    return res[n][x1][y1][x2][y2] = ans;
}
int main()
{
    memset(sum, 0, sizeof(sum));
    memset(res, -1, sizeof(res));
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1, row = 0; j <= 8; j++)
        {
            cin >> board[i][j];
            row += board[i][j];
            sum[i][j] += sum[i - 1][j] + row;
        }
    double ans = n * pro(1, 1, 8, 8, n) - sum[8][8] * sum[8][8];
    cout << setiosflags(ios::fixed) << setprecision(3) << sqrt(ans / (n * n)) << endl;
    return 0;
}