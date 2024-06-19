#include <bits/stdc++.h>
using namespace std;
int n,m,vis[10][10],num[10][10],dx[4]={0,1,1,1},dy[4]={1,-1,0,1},ans;
#define check(x,y) (x>=0&&x<n&&y>=0&&y<m)
void made(int x,int y,vector<int>& cont,int tag=0){
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(!check(xx,yy))continue;
        if(!tag)vis[xx][yy]=cont[i];
        else vis[xx][yy]=1;
    }
}
void dfs(int cur,int mm){
    if(cur>=n*m){
        ans=max(ans,mm);
        return ;
    }
    int x=cur/m,y=cur%m,tmp=cur+1;
    vector<int>cont;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(!check(xx,yy))continue;
        cont.push_back(vis[xx][yy]);
    }
    while(tmp<n*m&&vis[tmp/m][tmp%m])tmp++;
    if(tmp>=n*m){
        ans=max(ans,mm+num[x][y]);
        return ;
    }
    vis[x][y]=1;
    dfs(tmp,mm);
    made(x,y,cont,1);
    while(tmp<n*m&&vis[tmp/m][tmp%m])tmp++;
    if(tmp>=n*m){
        ans=max(ans,mm+num[x][y]);
        vis[x][y]=0;
        made(x,y,cont);
        return ;
    }
    dfs(tmp,mm+num[x][y]);
    vis[x][y]=0;
    made(x,y,cont);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>num[i][j];
            vis[i][j]=0;
        }
        dfs(0,0);
        cout<<ans<<"\n";
    }   
    return 0;
}