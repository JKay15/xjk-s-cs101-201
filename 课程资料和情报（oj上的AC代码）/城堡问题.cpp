#include <bits/stdc++.h>
using namespace std;
int citedal[51][51],m,n,vis[51][51],total,mmax,cur;
#define check(x,y) (x>=1&&x<=m&&y>=1&&y<=n&&!vis[x][y])
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if((!(citedal[x][y]&(1<<i)))&&check(xx,yy)){
            vis[xx][yy]=1;
            cur++;
            dfs(xx,yy);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)cin>>citedal[i][j];
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
        if(!vis[i][j]){
            vis[i][j]=cur=1;
            total++;
            dfs(i,j);
            mmax=max(mmax,cur);
        }
    }
    cout<<total<<"\n"<<mmax;    
    return 0;
}