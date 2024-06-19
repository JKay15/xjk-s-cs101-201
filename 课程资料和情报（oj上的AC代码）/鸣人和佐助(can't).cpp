//依然是vis数组的特殊处理
#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
int m,n,T,vis[maxn][maxn];
char board[maxn][maxn];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
#define check(x,y) (x>=1&&x<=m&&y>=1&&y<=n)
struct node{
    int x,y,step,T;
    node(){}
    node(int a,int b,int c,int t=0):x(a),y(b),step(c),T(t){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(vis,-1,sizeof(vis));
    cin>>m>>n>>T;
    queue<node> q;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
        cin>>board[i][j];
        if(board[i][j]=='@'){
            vis[i][j]=T;
            q.push({i,j,0,T});
        }
    }
    int t=0x7777777,suc=0;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(board[cur.x][cur.y]=='+'){
            suc=1;
            t=min(t,cur.step);
        }
        for(int i=0;i<4;i++){
            int xx=cur.x+dx[i],yy=cur.y+dy[i];
            if(check(xx,yy)){
                if(board[xx][yy]=='#'&&cur.T-1>vis[xx][yy]&&cur.T>0){
                    vis[xx][yy]=cur.T-1;
                    q.push({xx,yy,cur.step+1,cur.T-1});
                }else if((board[xx][yy]=='*'||board[xx][yy]=='+')&&vis[xx][yy]<cur.T){
                    vis[xx][yy]=cur.T;
                    q.push({xx,yy,cur.step+1,cur.T});
                }
            }
        }
        if(suc)break;
    }
    if(t<0x7777777)cout<<t<<"\n";
    else cout<<-1<<"\n";
    return 0;
}