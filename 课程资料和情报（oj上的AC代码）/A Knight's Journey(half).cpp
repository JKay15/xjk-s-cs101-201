//q，p的输入顺序问题，代码逻辑没毛病
#include <bits/stdc++.h>
using namespace std;
int p,q,vis[30][30],total;
string ans;
#define check(x,y) (x>=1&&x<=q&&y>=1&&y<=p)
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
string name(int x,int y){
    return string(1,'A'+x-1)+to_string(y);
}
bool dfs(int x,int y){
    if(total==p*q)return 1;
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(check(xx,yy)&&!vis[xx][yy]){
            ans+=name(xx,yy);
            vis[xx][yy]=1;
            total++;
            if(dfs(xx,yy))return 1;
            total--;
            vis[xx][yy]=0;
            ans=ans.substr(0,ans.length()-2);
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Scenario #"<<i<<":\n";
        ans="";
        cin>>p>>q;
        int suc=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=q;i++){
            for(int j=1;j<=p;j++){
                ans+=name(i,j);
                total=vis[i][j]=1;
                if(dfs(i,j)){
                    suc=1;
                    break;
                }
                ans="";
                total=vis[i][j]=0;
            }
            if(suc)break;
        }
        if(suc)cout<<ans<<"\n\n";
        else cout<<"impossible\n\n";
    }
    return 0;
}