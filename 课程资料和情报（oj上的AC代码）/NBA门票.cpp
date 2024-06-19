#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
int price[7]={50,100,250,500,1000,2500,5000},num[7],N,dp[7][20005];
int dfs(int i,int res){
    if(i>=7){
        if(!res)return dp[i][res]=0;
        return INF;
    }
    if(dp[i][res]!=-1)return dp[i][res];
    int ans=INF;
    for(int j=0;j<=num[i];j++){
        if(j*price[i]/50>res)break;
        else  ans=min(ans,j+dfs(i+1,res-j*price[i]/50));
    }
    return dp[i][res]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i=0;i<7;i++)cin>>num[i];
    int ans=dfs(0,N/50);
    if(ans==INF)cout<<"Fail";
    else cout<<ans;
    return 0;
}