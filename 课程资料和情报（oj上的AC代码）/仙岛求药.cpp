#include <bits/stdc++.h>
using namespace std;
char mat[25][25];
bool vis[25][25];
int m,n;
struct node{
    int x,y;
    int step;
    node(){}
    node(int x,int y,int z):x(x),y(y),step(z){}
};
#define check(x,y) (x>=1&&x<=m&&y>=1&&y<=n)
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>m>>n&&m){
        memset(vis,0,sizeof(vis));
        memset(mat,0,sizeof(mat));
        node root;
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            char t;
            cin>>t;
            mat[i][j]=(t=='@')?0:((t=='.')?1:((t=='#')?2:3));
            if(!mat[i][j])root={i,j,0};
        }
        vis[root.x][root.y]=1;
        queue<node> q;
        q.push(root);
        bool suc=0;
        node cur;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=cur.x+dx[i],yy=cur.y+dy[i];
                if(check(xx,yy)&&!vis[xx][yy]){
                    if(mat[xx][yy]==3){
                        suc=1;
                        break;
                    }else if(mat[xx][yy]==1){
                        q.push(node{xx,yy,cur.step+1});
                        vis[xx][yy]=1;
                    }
                }
            }
            if(suc)break;
        }
        if(suc)cout<<cur.step+1<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}