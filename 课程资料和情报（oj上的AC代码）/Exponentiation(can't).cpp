#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;
int tmp[200];
int res[200];
int n;
int decimal;
string x;
void process()
{
    int pre = 0;
    for (int i = 0; i <= x.length() - 1; i++)
    {
        if (x[i] == '0')
        {
            pre++;
        }
        else
        {
            break;
        }
    }
    int last = 0;
    int tag = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        if (x[i] == '.')
        {
            tag = 1;
            break;
        }
    }
    for (int i = x.length() - 1; i >= 0; i--)
    {
        if (x[i] == '0')
        {
            last++;
        }
        else
        {
            break;
        }
    }
    if (tag == 0)
        last = 0;
    if (pre == x.length() || pre + last == x.length())
    {
        x = "0";
    }
    else
    {
        x = x.substr(pre, x.length() - pre - last);
    }
    for (int i = x.length() - 1; i >= 0; i--)
    {
        if (x[i] != '.')
        {
            tmp[++tmp[0]] = x[i] - '0';
            res[++res[0]] = tmp[tmp[0]];
        }
        else
        {
            decimal = x.length() - i - 1;
        }
    }
}
void chengji()
{
    int cont[200] = {0};
    for (int i = 1; i <= tmp[0]; i++)
    {
        for (int j = 1; j <= res[0]; j++)
        {
            cont[j + i - 1] += res[j] * tmp[i];
        }
    }
    for (int i = 1; i <= tmp[0] + res[0]; i++)
    {
        if (cont[i] >= 10)
        {
            cont[i + 1] += cont[i] / 10;
            cont[i] %= 10;
            res[i] = cont[i];
        }
        else
        {
            res[i] = cont[i];
        }
        if (i < tmp[0] + res[0])
            cont[0]++;
        else
        {
            if (cont[i] != 0)
                cont[0]++;
        }
    }
    res[0] = cont[0];
}
void exponentiation(int n)
{
    for (int i = 1; i < n; i++)
        chengji();
}
int count_zero()
{
    int cnt = 0;
    for (int i = 1; i <= res[0]; i++)
    {
        if (res[i] == 0)
            cnt++;
        else
            return cnt;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> x >> n)
    {
        memset(tmp, 0, sizeof(tmp));
        memset(res, 0, sizeof(res));
        decimal = 0;
        process();
        exponentiation(n);
        int cnt = count_zero();
        cnt = cnt > decimal ? decimal : cnt;
        res[0]=res[0]>=decimal*n? res[0]:decimal*n+1;

        for (int i = res[0]; i >= 1 + cnt; i--)
        {
            if ((i == decimal * n + 1 && res[i] != 0) || (i != decimal * n + 1) || decimal == 0)
                cout << res[i];
            if (i == decimal * n + 1 && decimal != 0)
            {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}