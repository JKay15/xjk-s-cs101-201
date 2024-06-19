//又死在单调队列优化的bfs上，实在是很惭愧，当然，dijkstra也不会是很难受的事情
//vis设置的时机也有讲究，咱们设置错了
#include <bits/stdc++.h>
using namespace std;
int n,m,p,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},sx,sy,ex,ey;
vector<vector<string>> mmap;
vector<vector<bool>> vis;
#define check(x,y) (x>=0&&x<m&&y>=0&&y<n)
struct node{
    int x,y,val;
    node(int x=0,int y=0,int v=0):x(x),y(y),val(v){}
    bool operator<(const node&a)const{
        if(val==a.val){
            if(x==a.x)return y>a.y;
            return x>a.x;
        }
        return val>a.val;
    }
};
int bfs(){
    priority_queue<node> q;
    q.push({sx,sy,0});
    while(!q.empty()){
        node cur=q.top();q.pop();
        vis[cur.x][cur.y]=1;
        if(cur.x==ex&&cur.y==ey)return cur.val;
        for(int i=0;i<4;i++){
            int xx=cur.x+dx[i],yy=cur.y+dy[i];
            if(check(xx,yy)&&!vis[xx][yy]&&mmap[xx][yy]!="#"){
                q.push({xx,yy,cur.val+abs(stoi(mmap[cur.x][cur.y])-stoi(mmap[xx][yy]))});
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>p;
    mmap.resize(m);vis.resize(m);
    for(int i=0;i<m;i++){
        mmap[i].resize(n);vis[i].resize(n);
        for(int j=0;j<n;j++)cin>>mmap[i][j];
    }
    while(p--){
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)vis[i][j]=0;
        cin>>sx>>sy>>ex>>ey;
        if(mmap[sx][sy]=="#"||mmap[ex][ey]=="#")cout<<"NO\n";
        else{
            int ans=bfs();
            if(ans==-1)cout<<"NO\n";
            else cout<<ans<<"\n";
        }
    }
    return 0;
}