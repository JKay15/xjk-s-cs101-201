//贪心失败啦！！！！
// #include <bits/stdc++.h>
// using namespace std;
// bool board[105][12];
// int num[105][12],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},n,m;
// #define check(x,y) (x>=0&&x<n&&y>=0&&y<m)
// struct node{
//     int x,y,cnt;
//     node(int a=0,int b=0,int c=0):x(a),y(b),cnt(c){}
//     bool operator<(const node&x)const{
//         return cnt<x.cnt;
//     }
// };
// vector<node> cont;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//     for(int j=0;j<m;j++){
//         char tmp;
//         cin>>tmp;
//         board[i][j]=(tmp=='P');
//     }
//     for(int i=0;i<n;i++)
//     for(int j=0;j<m;j++){
//         if(!board[i][j])continue;
//         for(int k=0;k<4;k++){
//             int xx=i+dx[k],yy=j+dy[k];
//             if(check(xx,yy)&&board[xx][yy])num[i][j]++;
//             xx+=dx[k],yy+=dy[k];
//             if(check(xx,yy)&&board[xx][yy])num[i][j]++;
//         }
//         cont.push_back({i,j,num[i][j]});
//     }
//     while(cont.size()){
//         sort(cont.begin(),cont.end());
//         int i=cont[0].x,j=cont[0].y;
//         for(int k=0;k<4;k++){
//             int xx=i+dx[k],yy=j+dy[k];
//             if(check(xx,yy)&&board[xx][yy])num[i][j]++;
//             xx+=dx[k],yy+=dy[k];
//             if(check(xx,yy)&&board[xx][yy])num[i][j]++;
//         }
//         cont.erase(cont.begin());
//     }


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int m,n,top,state[110],cur[110],num[110],dp[110][110][110];
char tu[110][20];
inline bool ok(int x)
{
    if(x&(x<<1)) return false;
    if(x&(x<<2)) return false;
    return true;
}
inline void init()
{
    int tol=1<<n;
    top=0;
    for(int i=0; i<tol; i++)
    {
        if(ok(i)) state[++top]=i;
    }
}
inline bool fit(int x,int k)
{
    if(x&cur[k]) return false;
    return true;
}
inline int icount(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x=x&(x-1);
    }
    return cnt;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        for(int i=1; i<=m; i++)
            scanf("%s",tu[i]+1);
        for(int i=1;i<=m;i++)
        {
            cur[i]=0;
            for(int j=1;j<=n;j++)
            {
                if(tu[i][j]=='H')
                    cur[i]+=(1<<(n-j));
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=top; i++)
        {
            num[i]=icount(state[i]);
            if(fit(state[i],1))
                dp[1][1][i]=num[i];
        }
        for(int i=2; i<=m; i++)
        {
            for(int t=1; t<=top; t++)
            {
                if(!fit(state[t],i)) continue;//符合本行
                for(int j=1; j<=top; j++)
                {
                    if(state[j]&state[t]) continue;//符合上一行
                    for(int k=1; k<=top; k++) //符合上上行
                    {
                        if(state[k]&state[t]) continue;
                        if(state[k]&state[j]) continue;
                        dp[i][j][t]=max(dp[i][j][t],(dp[i-1][k][j]+num[t]));
                    }
                }
            }
        }
        int maxx=-1;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=top; j++)
            {
                for(int k=1; k<=top; k++)
                {
                    maxx=max(maxx,dp[i][j][k]);
                }
            }
        }
        printf("%d\n",maxx);
    }
    return  0;
}