//用边的平行判断是慢的，需要用对角线交点是中点才行
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1005;
struct node
{
    int x,y;
}a[maxn],mid[550000];
bool cmp(const node &a1,const node &b1)
{
    if(a1.x!=b1.x) return a1.x<b1.x;
    else return a1.y<b1.y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                mid[++num].x=a[j].x+a[i].x,mid[num].y=a[j].y+a[i].y;
            }
        }
        sort(mid+1,mid+1+num,cmp);
 
        int ans=1,sum=0;
        for(int i=1; i<num; i++)
        {
            if(mid[i].x==mid[i+1].x&&mid[i].y==mid[i+1].y) ans++;
            else
            {
                sum=sum+(ans-1)*ans/2;   // 转化为能组成的平行四边形的个数
                ans=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int t,n,ans;
// vector<pair<int,int>> po;
// pair<int,int> check(int i,int j,int p){
//     return {-po[i].first+po[j].first+po[p].first,-po[i].second+po[j].second+po[p].second};
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>t;
//     while(t--){
//         cin>>n;
//         po.resize(n);
//         for(int i=0;i<n;i++)cin>>po[i].first>>po[i].second;
//         sort(po.begin(),po.end());
//         ans=0;
//         for(int i=0;i<=n-4;i++)
//         for(int j=i+1;j<=n-3;j++)
//         for(int p=j+1;p<=n-2;p++){
//             pair<int,int> need=check(i,j,p);
//             auto where=lower_bound(po.begin()+p+1,po.end(),need);
//             if(where->first==need.first&&where->second==need.second)ans++;
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }