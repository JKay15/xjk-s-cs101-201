#include <bits/stdc++.h>
using namespace std;
int x,y,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0},sx,sy;
char board[105][105];
bool vis[105][105][2];
#define check(xx,yy) (xx>0&&xx<=x&&yy>0&&yy<=y)
struct node{
    int xx,yy,ok=0;
    string ans;
    node(){}
    node(int a,int b):xx(a),yy(b){
        ans=to_string(a)+" "+to_string(b)+"\n";
    }
}res;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>y;
    for(int i=1;i<=x;i++)
    for(int j=1;j<=y;j++){
        cin>>board[i][j];
        if(board[i][j]=='R'){sx=i;sy=j;vis[sx][sy][0]=1;}
    }
    queue<node> q;
    q.push({sx,sy});
    while(!q.empty()){
        node cur=q.front();
        if(board[cur.xx][cur.yy]=='C'&&cur.ok){res=cur;break;}
        q.pop();
        for(int i=0;i<4;i++){
            int xx=cur.xx+dx[i],yy=cur.yy+dy[i];
            if(check(xx,yy)&&!vis[xx][yy][cur.ok]&&board[xx][yy]!='1'){
                node tmp=cur;
                tmp.xx=xx;tmp.yy=yy;
                tmp.ans+=to_string(xx)+" "+to_string(yy)+"\n";
                if(board[xx][yy]=='Y')tmp.ok=1;
                vis[xx][yy][tmp.ok]=1;
                q.push(tmp);
            }
        }
    }
    cout<<res.ans;
    return 0;
}