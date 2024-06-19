#include <bits/stdc++.h>
using namespace std;
int w,h,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},vis[21][21],board[21][21];
#define check(x,y) (x>=0&&x<h&&y>=0&&y<w)
int dfs(int x,int y){
    int ans=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(check(xx,yy)&&!vis[xx][yy]&&board[xx][yy]){
            vis[xx][yy]=1;
            ans+=dfs(xx,yy);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>w>>h&&w){
        memset(vis,0,sizeof(vis));
        int sx,sy;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            char tmp;
            cin>>tmp;
            board[i][j]=((tmp=='#')?0:1);
            if(tmp=='@'){
                sx=i;sy=j;
                vis[i][j]=1;
            } 
        }
        cout<<dfs(sx,sy)<<"\n";
    }
    return 0;
}