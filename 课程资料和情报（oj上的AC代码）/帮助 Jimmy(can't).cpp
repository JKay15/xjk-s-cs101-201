#include <bits/stdc++.h>
#define maxn 1100
#define inf 99999
using namespace std;
int t,n,x,y,MAX;
struct Plat
{
    int lx,rx,h;
}p[maxn];
bool cmp(Plat a,Plat b)
{
    return a.h>b.h;
}
int ltime[maxn];
int rtime[maxn];
int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&MAX);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&p[i].lx,&p[i].rx,&p[i].h);
            if(p[i].lx>p[i].rx)
                swap(p[i].lx,p[i].rx);
        }
        p[0].lx=p[0].rx=x,p[0].h=y;
        p[n+1].lx=-20001,p[n+1].rx=20001,p[n+1].h=0;
        sort(p+1,p+n+1,cmp);
        for(i=n;i>=0;i--)
        {
            for(j=i+1;j<=n+1;j++)
            {
                if(p[i].lx>=p[j].lx&&p[i].lx<=p[j].rx)
                {
                    if(p[i].h-p[j].h>MAX)
                        ltime[i]=inf;
                    else if(j==n+1)
                        ltime[i]=p[i].h;
                    else
                        ltime[i]=p[i].h-p[j].h+min(ltime[j]+p[i].lx-p[j].lx,rtime[j]+p[j].rx-p[i].lx);
                    break;
                }
            }
            for(j=i+1;j<=n+1;j++)
            {
                if(p[i].rx>=p[j].lx&&p[i].rx<=p[j].rx)
                {
                    if(p[i].h-p[j].h>MAX)
                        rtime[i]=inf;
                    else if(j==n+1)
                        rtime[i]=p[i].h;
                    else
                        rtime[i]=p[i].h-p[j].h+min(ltime[j]+p[i].rx-p[j].lx,rtime[j]+p[j].rx-p[i].rx);
                    break;
                }
            }
        }
        printf("%d\n",min(ltime[0],rtime[0]));
    }
    return 0;
}
//感觉思路和答案类似，但是就是TLE了，很诡异
// #include <bits/stdc++.h>
// using namespace std;
// int n,x,y,m;
// #define INF numeric_limits<int>::max()
// struct plain{
//     int l,r,h;
//     bool operator<(const plain&x)const{
//         return h>x.h;
//     }
// };
// vector<plain> data1;
// int lmin[1005],rmin[1005];
// void cover(pair<bool,bool>& ok,int l,int r,int i){
//     if(l<=data1[i].l){
//         if(r>=data1[i].r)ok={0,0};
//         else ok={0,1};
//     }else ok={1,0};
// }
// int dfs(int cx,int i){
//     if(lmin[i]>=0&&rmin[i]>=0)return min(data1[i].r-cx+rmin[i],cx-data1[i].l+lmin[i]);
//     if(i==n+1)return 0;
//     pair<bool,bool> ok={1,1};
//     int ans=0x7777777,ans1=0x7777777;
//     for(int j=i+1;j<n+2;j++){
//         if(data1[i].h-data1[j].h>m)break;
//         else if(ok.first||ok.second){
//             if(ok.first&&data1[j].l<=data1[i].l){
//                 int tt=(data1[i].h-data1[j].h+dfs(data1[i].l,j));
//                 if(ans>tt)ans=tt;
//             }
//             if(ok.second&&data1[j].r>=data1[i].r){
//                 int tt=(data1[i].h-data1[j].h+dfs(data1[i].r,j));
//                 if(ans1>tt)ans1=tt;
//             }
//             cover(ok,data1[j].l,data1[j].r,i);
//         }else break;
//     }
//     lmin[i]=ans,rmin[i]=ans1;
//     return min(ans+cx-data1[i].l,ans1+data1[i].r-cx);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         cin>>n>>x>>y>>m;
//         data1.clear();
//         data1.resize(n+2);
//         memset(lmin,-1,sizeof(lmin));
//         memset(rmin,-1,sizeof(rmin));
//         data1[0].l=data1[0].r=x;
//         data1[0].h=y;
//         for(int i=1;i<=n;i++)cin>>data1[i].l>>data1[i].r>>data1[i].h; 
//         data1[n+1].l=numeric_limits<int>::min(),data1[n+1].r=numeric_limits<int>::max();
//         data1[n+1].h=0;
//         sort(data1.begin(),data1.end());
//         cout<<dfs(x,0)<<"\n";
//     }

//     return 0;
// }