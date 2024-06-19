//我原本是讨论有几个盘子是有苹果的，如果盘子数小于苹果数，那么可以有1-盘子数的盘子放满，苹果减去这个数量，并且接下来只需要考虑这么多盘子，于是递归solve(苹果数-枚举的盘子数，盘子数)
//如果盘子数大于苹果数，那么可以有1-苹果数的盘子放满，接下来是一样的
//但是这个讨论似乎是错误的
//正解是讨论能否空盘，每次也只减少一个盘子或者把盘子放满一遍，不知道为啥他对了我错了
#include <bits/stdc++.h>
using namespace std;
int n,m,dp[15][15];
int solve(int x,int y){
    if(dp[x][y])return dp[x][y];
    if(x<=1||y==1)return dp[x][y]=1;
    int ans=(x>=y)?solve(x-y,y)+solve(x,y-1):solve(x,y-1);
    return dp[x][y]=ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){ 
        memset(dp,0,sizeof(dp));
        cin>>m>>n;
        cout<<solve(m,n)<<"\n";
    }
    return 0;
}