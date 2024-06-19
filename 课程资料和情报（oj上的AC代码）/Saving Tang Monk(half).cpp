//值得学习的广搜题目，用优先队列实现延迟问题
#include <bits/stdc++.h>
using namespace std;
int n,m,palace[105][105],cnt,vis[105][105][10],snakePos[105][105];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
#define check(x,y) (x>=0&&x<n&&y>=0&&y<n)
struct node{
    int x,y,step,key,snake;
    node(){}
    node(int a,int b,int c,int d,int e):x(a),y(b),step(c),key(d),snake(e){}
    bool operator<(const node&x)const{
        return step>x.step;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m&&n){
        memset(snakePos,0,sizeof(snakePos));
        memset(vis,0,sizeof(vis));
        pair<int,int> monk;
        node root;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            char tmp;
            cin>>tmp;
            palace[i][j]=((tmp=='K')?0:((tmp=='T')?-1:((tmp=='S')?-2:((tmp=='.')?-3:((tmp=='#')?-4:(tmp-'0'))))));
            if(palace[i][j]==-1)monk={i,j};
            else if(!palace[i][j])root={i,j,0,0,0};
            else if(palace[i][j]==-2)snakePos[i][j]=cnt++;
        }
        priority_queue<node> q;
        q.push(root);
        int suc=-1;
        while(!q.empty()){
            node cur=q.top();
            q.pop();
            if(cur.x==monk.first&&cur.y==monk.second&&cur.key==m){
                suc=cur.step;
                break;
            }
            for(int i=0;i<4;i++){
                int xx=cur.x+dx[i],yy=cur.y+dy[i],key=cur.key,step=cur.step+1,snake=cur.snake;
                if(palace[xx][yy]==cur.key+1)key++;
                if(!(check(xx,yy))||(vis[xx][yy][key])||(palace[xx][yy]==-4))continue;
                if(palace[xx][yy]==-2&&((cur.snake&(1<<snakePos[xx][yy]))==0))
                    step++,snake|=(1<<snakePos[xx][yy]);
                vis[xx][yy][key]=1;
                q.push({xx,yy,step,key,snake});
            }
        }
        if(suc>=0)cout<<suc<<"\n";
        else cout<<"impossible\n";
    }
    return 0;
}