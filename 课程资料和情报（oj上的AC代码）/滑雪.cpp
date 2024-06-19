#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int r,c,h[maxn][maxn],dp[maxn][maxn];
#define check(x,y) (x>=1&&x<=r&&y>=1&&y<=c)
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    int ans=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(check(xx,yy)&&h[xx][yy]<h[x][y])ans=max(ans,1+dfs(xx,yy));
    }
    return dp[x][y]=ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)cin>>h[i][j];
    int ans=0;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)ans=max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}