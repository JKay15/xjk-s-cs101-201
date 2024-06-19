//不知道为啥///因为起点也是可以重复经过的，只要step%K没有重复过就行，又是一道奇奇怪怪的vis数组
#include <bits/stdc++.h>
using namespace std;
int R,C,K,vis[105][105][15],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char board[105][105];
struct node{
    int x,y,step;
    node(){}
    node(int a,int b,int c):x(a),y(b),step(c){}
};
#define check(x,y) (x>=1&&x<=R&&y>=1&&y<=C)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>R>>C>>K;
        node root,goal;
        memset(board,'c',sizeof(board));
        for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
            cin>>board[i][j];
            if(board[i][j]=='S')root={i,j,0};
            if(board[i][j]=='E')goal={i,j,0};
        }
        memset(vis,0,sizeof(vis));
        queue<node> q;
        vis[root.x][root.y][0]=0;
        q.push(root);
        node cur;
        int suc=0;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=cur.x+dx[i],yy=cur.y+dy[i];
                if(xx==goal.x&&yy==goal.y){
                    cout<<cur.step+1<<"\n";
                    suc=1;
                    break;
                }
                if(check(xx,yy)&&!(vis[xx][yy][(cur.step+1)%K])){
                    if(board[xx][yy]=='.'||board[xx][yy]=='E'||board[xx][yy]=='S'){
                        q.push({xx,yy,cur.step+1});
                        vis[xx][yy][(cur.step+1)%K]=1;
                    }
                    if(board[xx][yy]=='#'&&!((cur.step+1)%K)){
                        q.push({xx,yy,cur.step+1});
                        vis[xx][yy][(cur.step+1)%K]=1;
                    }
                }
            }
            if(suc)break;
        }
        if(!suc)cout<<"Oop!\n";
    }
    return 0;
}
