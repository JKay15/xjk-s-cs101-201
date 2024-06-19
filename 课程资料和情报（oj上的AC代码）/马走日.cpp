#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,vis[10][10],ans;
#define check(x,y) (x>=0&&x<n&&y>=0&&y<m)
int dx[8]={-1,1,-1,1,2,2,-2,-2};
int dy[8]={2,2,-2,-2,1,-1,1,-1};
void dfs(int x1,int y1,int cnt){
    if(cnt==n*m){
        ans++;
        return ;
    }
    for(int i=0;i<8;i++){
        int xx=x1+dx[i],yy=y1+dy[i];
        if(!vis[xx][yy]&&check(xx,yy)){
            vis[xx][yy]=1;
            dfs(xx,yy,cnt+1);
            vis[xx][yy]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>x>>y;
        vis[x][y]=1;
        dfs(x,y,1);
        cout<<ans<<"\n";
    }

    return 0;
}