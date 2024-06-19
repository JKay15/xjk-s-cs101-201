//这里mmax会到51，dp只开51位的话会出界。。。
//给一个更优的做法，dp
#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
int dp[N][N], dp1[N], dp2[N];
int main() {
	for (int n, k; scanf("%d%d", &n, &k) == 2;) {
		memset(dp, 0, sizeof(dp));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		dp[0][0]=1,dp1[0]=1,dp2[0]=1;
		for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		for (int q = k; q >= 1; q--)
			dp[j][q] += dp[j - i][q - 1];
		printf("%d\n", dp[n][k]);
		for (int i = 1; i <= n; i++)
		for (int j = n; j >= i; j--)
			dp1[j] += dp1[j - i];
		printf("%d\n", dp1[n]);
		for (int i = 1; i <= n; i += 2)
			for (int j = i; j <= n; j++)
				dp2[j] += dp2[j - i];
		printf("%d\n", dp2[n]);
	}
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std; 
// int n,k;
// int dp[52][52];
// int dp2[51][51];
// int dp1[51][51][51];
// int dfs(int x,int mmax){
//     if(dp[x][mmax]!=-1)return dp[x][mmax];
//     if(mmax==1&&x)return dp[x][mmax]=0;
//     if(x<=1)return dp[x][mmax]=1;
//     int total=0;
//     for(int i=min(mmax-1,x);i>=1;i--)total+=dfs(x-i,i);
//     return dp[x][mmax]=total;
// }
// int dfs1(int x,int mmax,int total){
//     if(dp1[x][mmax][total]!=-1)return dp1[x][mmax][total];
//     if(x<=1||mmax==1){
//         if(total+x==k)return dp1[x][mmax][total]=1;
//         else return dp1[x][mmax][total]=0;
//     }
//     int total1=0;
//     for(int i=min(mmax,x);i>=1;i--)total1+=dfs1(x-i,i,total+1);
//     return dp1[x][mmax][total]=total1;
// }
// int dfs2(int x,int mmax){
//     if(dp2[x][mmax]!=-1)return dp2[x][mmax];
//     if(x<=1||mmax==1)return dp2[x][mmax]=1;
//     int total=0;
//     int i=(x%2)?min(x,mmax):min(x-1,mmax);
//     for(;i>=1;i-=2)total+=dfs2(x-i,i);
//     return dp2[x][mmax]=total;
// }
// int main(){
//     while(cin>>n>>k){
//         memset(dp,-1,sizeof(dp));
//         memset(dp1,-1,sizeof(dp1));
//         memset(dp2,-1,sizeof(dp2));
//         cout<<dfs1(n,n,0)<<"\n";
//         cout<<dfs(n,n+1)<<"\n";
//         cout<<dfs2(n,((n%2)?n:n-1))<<"\n";
//     }
//     return 0;
// }