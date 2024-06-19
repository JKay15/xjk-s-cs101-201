#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char dir[]="EWSN",board[105][105];
int vis[50][50][50][50],n,tag;
#define check(a,b) (a>=0&&a<n&&b>=0&&b<n) 
struct node{
    int x1,y1,x2,y2,dis,id,pre;
    char h,H;
    node(){}
    node(int a,int b,int c,int d,int e,int f,int g):x1(a),y1(b),x2(c),y2(d),dis(e),id(f),pre(g){}
    friend bool operator<(const node&x,const node&y){
        return x.dis<y.dis;
    }
}s[1000005];
priority_queue<node> q;
int distance(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void solve(int x1,int y1,int x2,int y2){
    q={};
    memset(vis,-1,sizeof(vis));
    tag=0;
    int dis=distance(x1,y1,x2,y2);
    node x{x1,y1,x2,y2,dis,tag,-1};
    s[tag++]=x;
    q.push(x);
    while(!q.empty()){
        node cur = q.top();
        q.pop();
        if(board[cur.x1][cur.y1]=='s'&&board[cur.x2][cur.y2]=='S'){
            printf("%.2f\n",sqrt(1.0*cur.dis));
            stack<char> s1,s2;
            while(cur.pre!=-1){
                if(cur.H!='e')s1.push(cur.H);
                if(cur.h!='e')s2.push(cur.h);
                cur=s[cur.pre];
            }
            while(!s1.empty()){
                printf("%c",s1.top());
                s1.pop();
            }
            puts("");
            while(!s2.empty()){
                printf("%c",s2.top());
                s2.pop();
            }
            puts("");
            break;
        }
        for(int i=0;i<4;i++){
            int tmp1=cur.x1+dx[i],tmp2=cur.y1+dy[i];
            char moveh=dir[i];
            if(board[cur.x1][cur.y1]=='s'){
                tmp1=cur.x1,tmp2=cur.y1,moveh='e';
            }
            if(check(tmp1,tmp2)&&board[tmp1][tmp2]!='*'&&board[tmp1][tmp2]!='S'&&board[tmp1][tmp2]!='H'){
                for(int j=0;j<4;j++){
                    int tmp3=cur.x2+dx[j],tmp4=cur.y2+dy[j];
                    char moveH=dir[j];
                    if(board[cur.x2][cur.y2]=='S'){
                        tmp3=cur.x2,tmp4=cur.y2,moveH='e';
                    }
                    if(check(tmp3,tmp4)&&board[tmp3][tmp4]!='*'&&board[tmp3][tmp4]!='s'&&board[tmp3][tmp4]!='h'){
                        dis=distance(tmp1,tmp2,tmp3,tmp4);
                        dis=min(dis,cur.dis);
                        if(dis>vis[tmp1][tmp2][tmp3][tmp4]||vis[tmp1][tmp2][tmp3][tmp4]==-1){
                            x.x1=tmp1,x.y1=tmp2,x.x2=tmp3,x.y2=tmp4;
                            x.id=tag;
                            x.dis=dis;
                            x.pre=cur.id;
                            x.h=moveh;
                            x.H=moveH;
                            s[tag++]=x;
                            q.push(x);
                            vis[tmp1][tmp2][tmp3][tmp4]=dis;
                        }
                    }
                    if(board[cur.x2][cur.y2]=='S')break;
                }
            }
            if(board[cur.x1][cur.y1]=='s')break;
        }
    }
}
int hx,hy,Hx,Hy;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>board[i][j];
                if(board[i][j]=='h'){
                    hx=i,hy=j;
                }else if(board[i][j]=='H'){
                    Hx=i,Hy=j;
                }
            }
        }
        solve(hx,hy,Hx,Hy);
    }
    return 0;
}