#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#define ll long long int
using namespace std;
const int maxn = 10010;
int wire[maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        wire[i] = int(t * 100);
        sum += wire[i];
    }
    sort(wire, wire + n);
    ll l = 0;
    ll r=min(sum/k, (ll)wire[n-1]);
    ll res = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if(mid==0){
            res=0;
            break;
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += wire[i] / mid;
        }
        if (cnt >= k)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    double ans=1.0*res/100;
    printf("%.2f",ans);

    return 0;
}