#include <bits/stdc++.h>
using namespace std;
const int maxn=405;
#define check(x,y) (x>=0&&x<n&&y>=0&&y<m)
int h[maxn][maxn],n,m,vis[maxn][maxn],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct comp{
    bool operator()(array<int,3>& x,array<int,3>& y){
        return x[0]>y[0];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cin>>h[i][j];
        vis[i][j]=numeric_limits<int>::max();
    }
    priority_queue<array<int,3>,vector<array<int,3>>,comp> q;
    q.push({0,0,0});
    vis[0][0]=1;
    int ans=numeric_limits<int>::max();
    while(q.size()){
        auto cur=q.top();
        q.pop();
        if(cur[1]==n-1&&cur[2]==m-1){
            ans=cur[0];
            break;
        }
        for(int i=0;i<4;i++){
            int xx=cur[1]+dx[i],yy=cur[2]+dy[i];
            if(check(xx,yy)){
                int mmax=max(cur[0],abs(h[cur[1]][cur[2]]-h[xx][yy]));
                if(vis[xx][yy]>mmax){
                    vis[xx][yy]=mmax;
                    q.push({mmax,xx,yy});
                }
            }
        }

    }
    cout<<ans<<"\n";
}
// #define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
// int dx[4]={0,0,-1,1};
// int dy[4]={1,-1,0,0};
// bool avai(int mid){
//     memset(vis,0,sizeof(vis));
//     queue<pair<int,int> > q;
//     q.push({1,1});
//     while(!q.empty()){
//         auto cur=q.front();
//         q.pop();
//         for(int i=0;i<4;i++){
//             int xx=cur.first+dx[i];
//             int yy=cur.second+dy[i];
//             if(xx==n&&yy==m)return 1;
//             if(check(xx,yy)&&!vis[xx][yy]){
//                 if(abs(h[xx][yy]-h[cur.first][cur.second])<=mid){
//                     vis[xx][yy]=1;
//                     q.push({xx,yy});
//                 }
//             }
//         }
//     }
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>m;
//     int l=2000000000,r=0;
//     for(int i=1;i<=n;i++)
//     for(int j=1;j<=m;j++){
//         cin>>h[i][j];
//         l=min(l,h[i][j]);
//         r=max(r,h[i][j]);
//     }
//     r=r-l,l=0;
//     int res=0;
//     while(l<=r){
//         int mid=(l+r)/2;
//         if(avai(mid)){
//             res=mid;
//             r=mid-1;
//         }else l=mid+1;
//     }
//     cout<<res;
//     return 0;
// }