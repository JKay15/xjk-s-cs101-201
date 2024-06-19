#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
int num[1005];
int dp[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (num[i] > num[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int mmax=0;
    for_each(dp+1,dp+n+1,[&mmax](int x){
        mmax=max(mmax,x);
    });
    cout<<mmax<<endl;

    return 0;
}