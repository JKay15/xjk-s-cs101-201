//为啥背包的dp不能对啊！！！
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-4;
const int N = 1000;
int n, k, a[N], b[N];
double y[N];

bool judge(double x) {
    for(int i = 0; i < n; i++) y[i] = a[i] - x * b[i];

    sort(y, y + n);

    double sum = 0;
    for(int i = n - 1; i >= k; i--) sum += y[i];

    return sum >= 0;
}

double bs()
{
    double left = 0, right = 1, mid;
    while(right - left > EPS) {
        mid = left + (right - left) / 2;
        if(judge(mid)) left = mid;
        else right = mid;
    }
    return mid * 100;
}

int main()
{
    while(~scanf("%d%d", &n, &k) && (n || k)) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);

        printf("%.0f\n", bs());
    }

    return 0;
}

// #define ll long long
// int n, k;
// ll a[1005];
// ll b[1005];
// pair<ll, ll> dp[1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while (cin >> n >> k && n)
//     {
//         memset(dp, 0, sizeof(dp));
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         for (int i = 1; i <= n; i++)
//             cin >> b[i];
//         dp[0] = pair{a[1], b[1]};
//         for (int i = 2; i <= n; i++)
//         {
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 if (j > 0)
//                 {
//                     double tmp1 = 1.0 * dp[j - 1].first / dp[j - 1].second;
//                     double tmp2 = 1.0 * (dp[j].first + a[i]) / (dp[j].second + b[i]);
//                     if (tmp1 > tmp2)
//                         dp[j] = dp[j - 1];
//                     else
//                         dp[j] = pair{dp[j].first + a[i], dp[j].second + b[i]};
//                 }
//                 else
//                 {
//                     dp[j] = pair{dp[j].first + a[i], dp[j].second + b[i]};
//                 }
//             }
//         }
//         cout << (int)(100.0 * dp[k].first / dp[k].second + 0.5) << endl;
//     }
//     return 0;
// }