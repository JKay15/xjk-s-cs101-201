//超时的方法，枚举的是某个点集最优覆盖是否是一个矩形
// #include <stdio.h>
// int x[15],y[15],area[1<<15],ans[1<<15],m;
// using namespace std;
// int main(){
//     int num,i,j,xs,ys,xl,yl,size,a,b;
//     while(1){
//         scanf("%d",&num);
//         for(int i=0;i<num;i++)scanf("%d%d",x+i,y+i);
//         size=(1<<num);
//         for(int i=1;i<size;i++){
//             ans[i]=2000*2000;
//             xl=yl=-1000,xs=ys=1000;
//             for(int j=0;j<num;j++)
//                 if((i>>j)&1){
//                     xl=(x[j]>xl)?x[j]:xl;
//                     xs=(x[j]<xs)?x[j]:xs;
//                     yl=(y[j]>yl)?y[j]:yl;
//                     ys=(y[j]<ys)?y[j]:ys;
//                 }
//             a=xl-xs,b=yl-ys;
//             if(!a)a=1;
//             if(!b)b=1;
//             area[i]=a*b;
//             if(i&(i-1))ans[i]=area[i];
//         }
//         area[0]=ans[0]=0;
//         for(int i=1;i<size;i++)
//         if(ans[i]==area[i])
//         for(int j=1;j<size;j++)
//         if(ans[i|j]>ans[i]+ans[j])ans[i|j]=ans[i]+ans[j];
//         printf("%d\n",ans[size-1]);
//     }
// }
// 只有矩阵和点两种元素，压缩矩阵嘛？10110一串二进制代表你用了第1,3，4个矩阵，好像你还并不知道有啥矩阵。不妨先从已知的点入手，令dp[S]表示要容纳点集S所需要的最小面积。那么我们可以遍历所有点集，从少到多进行dp，好的那么我们至少需要这样一个for循环
//接下来的问题就是如何进行转移了？直觉来看，被容纳的点集从S'=0000转移到S=0011至少需要一个矩阵包裹3,4两个点，但我们的矩阵从哪里来呢？我们不妨先把所有可能存在的n ( n − 1 ) / 2 n(n-1)/2n(n−1)/2个矩阵找到（以任意两个点为顶点最多有这么多矩阵），转移时我们从里面挑选一个面积最小的能包裹住3,4两个点的矩形R，然后dp[s]=dp[s']+area(R)
//现在矩阵已经找到了，那么对每一个状态，我们必须找到他在什么时候转移，并找到转移时的最小矩形面积。在一开始我们的第一个for循环已经写好了是遍历所有点集，那么我们不妨再遍历所有的矩阵，如果对当前的点集s,存在一个矩阵A，A含有s所没有的点，那么新的点集s ∪ A s\cup As∪A就可以从中产生，我们可以更新dp[s|A]=min(dp[s|A], dp[s]+area[A])，这样不断的找下去，对点集s ∪ A s\cup As∪A我们一定能找到所有组合中面积最小的
#include<bits/stdc++.h>
using namespace std;
#define MAX 16
#define inf 1000005
int n, dp[1 << 16], x[MAX], y[MAX];
//s[i]:第i个矩阵的覆盖范围 cnt:矩阵的数目 area[i]：第i个矩阵的面积
int s[MAX*MAX], cnt = 0, area[MAX*MAX];
int main() {
	while (cin >> n && n) {
		dp[0] = 0; cnt = 0;
		for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
		//找到所有矩阵
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				s[cnt] = 0;
				for (int k = 0; k < n; k++) {
					//k点在不在i，j点的矩阵范围内
					if ((x[k] - x[i])*(x[j] - x[k]) >= 0 && (y[k] - y[i])*(y[j] - y[k]) >= 0) {
						s[cnt] |= (1 << k);
					}
				}
				if (x[i] == x[j]) area[cnt] = abs(y[i] - y[j]);//两点共线
				else if (y[i] == y[j]) area[cnt] = abs(x[i] - x[j]);
				else area[cnt] = abs(x[i] - x[j])*abs(y[i] - y[j]);
				cnt++;
			}
		}
		//开始dp
		for (int i = 1; i < (1 << n); i++) dp[i] = inf;//初始化所有的面积都是inf，dp[0]=0
		for (int i = 0; i < (1 << n); i++) {
			for (int k = 0; k < cnt; k++) {
				if ((s[k] | i) != i) {//s[k]包含了i没有的元素，他们可以凑成一个更大的点集
					dp[s[k] | i] = min(dp[s[k] | i], dp[i] + area[k]);
				}
			}
		}
		cout << dp[(1 << n) - 1] << endl;
	}
}

//转化为旅行商问题目前的写法肯定是不行的，没有考虑到某些点会因为前面的枚举被包含在矩形内部，就不需要再讨论
//加了check还是不行，不知道为啥了
// #include <bits/stdc++.h>
// using namespace std;
// int n,dis[20][20],dp[1<<16][16],x[16],y[16];
// int check(int pos,int p){
//     for(int i=0;i<n;i++)
//     if(pos&(1<<i))
//     for(int j=i+1;j<n;j++)
//     if(pos&(1<<j)){
//         if(x[i]==x[j])if(max(y[i],y[j])>=y[p]&&min(y[i],y[j])<=y[p]&&x[p]<=x[i]+1&&x[p]>=x[i]-1)return 1;
//         if(max(x[i],x[j])>=x[p]&&min(x[i],x[j])<=x[p]&&max(y[i],y[j])>=y[p]&&min(y[i],y[j])<=y[p])return 1;
//     }
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>n&&n){
//         memset(dp,127,sizeof(dp));
//         for(int i=0;i<n;i++)cin>>x[i]>>y[i];
//         for(int i=0;i<n;i++)
//         for(int j=0;j<i;j++){
//             if(x[i]==x[j])dis[i][j]=dis[j][i]=abs(y[i]-y[j]);
//             else if(y[i]==y[j])dis[i][j]=dis[j][i]=abs(x[i]-x[j]);
//             else dis[i][j]=dis[j][i]=abs((x[i]-x[j])*(y[i]-y[j]));
//         }
//         for(int i=0;i<n;i++)dp[(1<<n)-1][i]=0;
//         for(int i=(1<<n)-1;i>=0;i--)
//         for(int j=0;j<n;j++)
//         if(!(i&(1<<j))){
//             int tag=check(i,j);
//             for(int k=0;k<n;k++)if(i&(1<<k))
//             dp[i][j]=min(dp[i][j],dp[i+(1<<j)][k]+((tag)?0:dis[j][k]));      
//         }
//         int ans=numeric_limits<int>::max();
//         for(int i=0;i<n;i++)ans=min(ans,dp[(1<<n)-1-(1<<i)][i]);
//         cout<<ans<<"\n";
//     }
//     return 0;
// }