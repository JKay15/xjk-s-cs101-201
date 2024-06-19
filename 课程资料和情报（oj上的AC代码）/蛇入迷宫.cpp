#include <bits/stdc++.h>
using namespace std;
int vis[105][105],bd[105][105],dx[2]={1,0},dy[2]={0,1},n;
#define check(x,y)(x>=0&&x<n&&y>=0&&y<n)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>bd[i][j];
    queue<array<int,4>> q;
    q.push({0,1,2,0});
    int ans=-1;
    while(q.size()){
        auto cur=q.front();
        int x1=cur[0],y1=cur[1],pos=cur[2];
        q.pop();
        if(x1==n-1&&y1==n-1&&pos==2){
            ans=cur[3];
            break;
        }
        for(int i=0;i<2;i++){
            int xx1=x1+dx[i],yy1=y1+dy[i];
            int xx2=xx1-dx[pos-1],yy2=yy1-dy[pos-1];
            if(check(xx1,yy1)&&!bd[xx1][yy1]&&!bd[xx2][yy2]&&((vis[xx1][yy1]&pos)==0)){
                vis[xx1][yy1]+=pos;
                q.push({xx1,yy1,pos,cur[3]+1});
            }
            if((pos==2&&i==0)||(pos==1&&i==1)){
                int tmp=((pos==2)?1:2);
                if(check(xx2,yy2)&&!bd[xx1][yy1]&&!bd[xx2][yy2]&&((vis[xx1][yy1]&tmp)==0)){
                    vis[xx2][yy2]+=tmp;
                    q.push({xx2,yy2,tmp,cur[3]+1});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}