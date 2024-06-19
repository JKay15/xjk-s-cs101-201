//把守卫当成两个点处理
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n,m;
int board[maxn][maxn],vis[maxn][maxn],t;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
#define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
struct node{
    int x,y,step;
    node(){}
    node(int a,int b,int c):x(a),y(b),step(c){}
};
void solve(){
    cin>>n>>m;
    node root;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char tmp;
        cin>>tmp;
        if(tmp=='r'){
            root.x=i;
            root.y=j;
            root.step=0;
            vis[i][j]=0;
        }else if(tmp=='@'||tmp=='a')vis[i][j]=1;
        else if (tmp=='x')vis[i][j]=2;
        else vis[i][j]=0;
        board[i][j]=((tmp=='@')?0:((tmp=='a')?1:((tmp=='r')?2:((tmp=='x')?3:4))));
    }
    queue<node> q;
    q.push(root);
    t=(1<<30);
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(board[cur.x][cur.y]==1){
            t=min(t,cur.step);
            break;
        }
        if(board[cur.x][cur.y]==3&&vis[cur.x][cur.y]==1){
            q.push({cur.x,cur.y,cur.step+1});
            vis[cur.x][cur.y]=0;
        }else{
            for(int i=0;i<4;i++){
                int xx=cur.x+dx[i],yy=cur.y+dy[i];
                if(check(xx,yy)&&vis[xx][yy]){
                    if(board[xx][yy]==3&&vis[xx][yy]==2){
                        q.push({xx,yy,cur.step+1});
                        vis[xx][yy]=1;
                    }else if(board[xx][yy]!=3){
                        q.push({xx,yy,cur.step+vis[xx][yy]});
                        vis[xx][yy]=0;
                    }
                }
            }
        }
    }
    if(t!=(1<<30))cout<<t<<"\n";
    else cout<<"Impossible\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}