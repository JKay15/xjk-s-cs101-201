#include <bits/stdc++.h>
using namespace std;
struct Hu
{
    int id, f, d;
} hu[26];
int n, h, tt, l[26], res[26], tmp[26], ans, now;
bool operator<(const Hu &a, const Hu &b)
{
    if (a.f == b.f)
        return a.id > b.id;
    else
        return a.f < b.f;
}
priority_queue<Hu> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n != 0)
    {
        cin >> h;
        h = h * 12;
        ans = -1;
        memset(res, 0, sizeof(res));
        for (int i = 0; i < n; i++)
        {
            cin >> hu[i].f;
            hu[i].id = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> hu[i].d;
        }
        l[0] = 0;
        for (int i = 1; i < n; i++)
        {
            cin >> l[i];
            l[i] += l[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            now = 0;
            while (!q.empty())
                q.pop();
            for (int j = 0; j <= i; j++)
            {
                q.push(hu[j]);
            }
            memset(tmp, 0, sizeof(tmp));
            tt = h - l[i];
            while (tt > 0)
            {
                tt--;
                Hu p = q.top();
                q.pop();
                tmp[p.id]++;
                now += p.f;
                p.f -= p.d;
                if (p.f < 0)
                {
                    p.f = 0;
                }
                q.push(p);
            }

            if (now > ans)
            {
                ans = now;
                for (int k = 0; k < n; k++)
                {
                    res[k] = tmp[k];
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << res[i] * 5 << ", ";
        }
        cout << res[n - 1] * 5 << endl;
        printf("Number of fish expected: %d \n", ans);

        if (n > 0)
            cout << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 30;
// int n,h;
// int ttime[maxn],f[maxn],d[maxn],t[maxn];
// int dp[maxn][1000];
// int dfs(int i,int leftt){
//     if(i>n)return 0;
//     if(leftt<=0)return 0;
//     if(dp[i][leftt]!=-1)return dp[i][leftt];
//     int tmp = 0;
//     int l=((d[i])?(min(leftt/5,f[i]/d[i]+((f[i]%d[i])?1:0))):(leftt/5));
//     for(int j=0;j<=l;j++){
//         if(leftt-5*j-t[i]<5){
//             tmp = max(tmp,(f[i]+f[i]-d[i]*(l-1))*l/2);
//             break;
//         }else
//             tmp = max(tmp,(f[i]+f[i]-d[i]*(j-1))*j/2+dfs(i+1,leftt-j*5-t[i]));
//     }
//     return dp[i][leftt]=tmp;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>n&&n){
//         memset(ttime,0,sizeof(ttime));
//         memset(dp,-1,sizeof(dp));
//         cin>>h;
//         for(int i=1;i<=n;i++)cin>>f[i];
//         for(int i=1;i<=n;i++)cin>>d[i];
//         for(int i=1;i<n;i++)cin>>t[i];
//         int T=dfs(1,h*60);
//         cout<<T<<endl;
//     }

//     return 0;
// }