#include <bits/stdc++.h>
using namespace std;
int n, m,ans=1;
bitset<10005> b;
int main()
{
    scanf("%d%d", &n, &m);
    int cnt = 0, tmp;
    while (n--)
    {
        cin>>tmp;
        if (!b[tmp])
        {
            b[tmp] = 1;
            ++cnt;
            if (cnt == m) 
            {
                ++ans;
                cnt = 0;
                b.reset();
            }
        }
    }
    printf("%d", ans);
    return 0;
}