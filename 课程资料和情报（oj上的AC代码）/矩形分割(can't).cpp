#include<bits/stdc++.h>
#define ll long long
int a[1000005];
int n,m,ans;
ll ssum=0;
void pre()
{
	scanf("%d %d",&m,&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int x,y,dx,dy;
		scanf("%d %d %d %d",&x,&y,&dx,&dy);
		for(int j=x;j<x+dx;j++)
		{
			a[j]+=dy;
            ssum+=dy;
		}
	}
}
ll che(int x)
{
	ll s1=0;
	ll s2=0;
	for(int i=0;i<x;i++) s1+=a[i];
    s2=ssum-s1;
	return s1-s2;
}
int main()
{
	pre(); 
	int l=0,r=m,mid;
	while(l+3<r)
	{
		mid=(l+r)/2;
		
		if(che(mid)>0) r=mid;
		else l=mid;
	}
	ll su=999999999999;
	for(int i=r;i>=l;i--) 
	{
		ll s=che(i);
		if(s>=0&&s<su) {su=s;ans=i;}
	}
	while(ans<m&&a[ans]==0) ans++;
	printf("%d",ans);
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// struct rect
// {
//     int x, y, w, h;
// };
// vector<rect> lis;
// int N, R;
// ll ssum=0;
// ll diff(int mid)
// {
//     ll tmp = 0;
//     for (auto rec : lis)
//     {
//         if (mid <= rec.x)
//             break;
//         else
//         {
//             if (mid < rec.x + rec.w)
//                 tmp += (mid - rec.x) * rec.h;
//             else
//                 tmp += rec.w * rec.h;
//         }
//     }
//     return 2*tmp-ssum;
// }
// bool comp(const rect &x, const rect &y)
// {
//     return x.x < y.x;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> R >> N;
//     lis.resize(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> lis[i].x >> lis[i].y >> lis[i].w >> lis[i].h;
//         ssum += lis[i].w * lis[i].h;
//     }
//     sort(lis.begin(), lis.end(), comp);
//     int l = 0, r = R, res = 0;
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (diff(mid) >= 0)
//         {
//             res = mid;
//             r = mid - 1;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     ll dif = diff(res);
//     for (int i = res+1; i <= R; i++)
//     {
//         ll tmp = diff(i);
//         if (tmp >= 0 && tmp <= dif)
//             res = i;
//         else if(tmp>dif)
//             break;
//     }
//     cout << res << endl;

//     return 0;
// }