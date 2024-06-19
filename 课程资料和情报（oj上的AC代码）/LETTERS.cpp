#include <bits/stdc++.h>
using namespace std;
int c,r,board[21][21],vis[26];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
#define check(x,y) (x>=0&&x<r&&y>=0&&y<c)
int dfs(int x,int y){
    int t=0;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(check(xx,yy)&&!vis[board[xx][yy]]){
            vis[board[xx][yy]]=1;
            t=max(t,1+dfs(xx,yy));
            vis[board[xx][yy]]=0;
        }
    }
    return t;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>r>>c;
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++){
        char x;
        cin>>x;
        board[i][j]=x-'A';
    }
    vis[board[0][0]]=1;
    cout<<1+dfs(0,0);
    return 0;
}