#include<bits/stdc++.h>
using namespace std;
int n,m,k;
#define N 1002
#define M 10002
int d[N],num[N],last[N],time1[N],date[N];
int ans=0;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	scanf("%d",&d[i]);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans-=a;
		num[c]++;
		last[b]=max(a,last[b]);
	}
	for(int i=2;i<=n;i++)
	time1[i]=max(time1[i-1],last[i-1])+d[i];
	int bz=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=n;j>=2;j--)
		{
			date[j]=num[j]; 
			if(last[j]<time1[j])date[j]+=date[j+1];
		}
		int maxn=0;
		for(int j=2;j<=n;j++)
		{
			if(date[j]>maxn&&d[j]>0)
			{
				maxn=date[j];
				bz=j;
			}
		}
		d[bz]--;
		for(int j=bz;j<=n;j++)time1[j]=max(time1[j-1],last[j-1])+d[j];
	} 
	for(int i=2;i<=n;i++)
	ans+=num[i]*time1[i];
	printf("%d",ans);
	return 0; 
}