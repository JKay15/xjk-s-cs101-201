#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
int n;
int height[105];
int dp1[105];
int dp2[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
        dp1[i] = dp2[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; ++j)
        {
            if (height[i] > height[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (height[i] > height[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int mmax = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp1[i] + dp2[i] > mmax)
        {
            mmax = dp1[i] + dp2[i];
        }
    }
    cout << n - mmax + 1 << endl;

    return 0;
}