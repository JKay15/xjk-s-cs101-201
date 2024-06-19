#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
const int maxn = 10005;
int n, s;
int c[maxn];
int y[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> s)
    {
        long long total = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i] >> y[i];
        }

        int tmp = c[1];
        std::for_each(c + 2, c + n + 1, [&tmp](int &x)
                      { x = (tmp + s >= x) ? x : tmp + s; 
                      tmp = x; });
        int i = 1;
        std::for_each(c + 1, c + n + 1, [&total, &i](int x)
                      { total += x * y[i++]; });
        cout<< total << endl;
    }
    return 0;
}