//没看到是若干组数据。。。。
#include <bits/stdc++.h>
using namespace std; 
int n;
int dp[51][51];
int dfs(int x,int mmax){
    if(dp[x][mmax])return dp[x][mmax];
    if(x<=1||mmax==1)return dp[x][mmax]=1;
    int total=0;
    for(int i=min(mmax,x);i>=1;i--)total+=dfs(x-i,i);
    return dp[x][mmax]=total;
}
int main(){
    while(cin>>n)cout<<dfs(n,n)<<"\n";
    return 0;
}