#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
struct Hotel
{
    int c, d;
} f[maxn];
int n, ans;
bool operator <(const Hotel &a, const Hotel &b)
{
    if (a.c == b.c)return a.d < b.d;
    return a.c < b.c;
}
void input()
{
    for (int i = 0; i < n; i++)scanf("%d%d", &f[i].c, &f[i].d);
}
void work()
{
    ans = 0;
    int maxd = 100000000;
    for (int i = 0; i < n; i++)
        if (f[i].d < maxd)
        {
            ans++;
            maxd = f[i].d;
        }
}
int main()
{
    while (scanf("%d", &n) != EOF && n != 0)
    {
        input();
        sort(f, f + n);
        work();
        printf("%d\n", ans);
    }
    return 0;
}