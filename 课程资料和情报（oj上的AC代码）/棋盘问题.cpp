#include <bits/stdc++.h>
using namespace std;
int n, k;
int vis_x[10];
int vis_y[10];
int board[10][10];
int dfs(int x,int total){
    if(x>n){
        return ((total==k)?1:0);
    }
    int tmp=dfs(x+1,total);
    for(int i=1;i<=n;i++){
        if(board[x][i]&&vis_y[i]==0){
            vis_x[x]=1;
            vis_y[i]=1;
            tmp+=dfs(x+1,total+1);
            vis_x[x]=0;
            vis_y[i]=0;
        }
    }
    return tmp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k && n > 0)
    {
        memset(vis_x,0,sizeof(vis_x));
        memset(vis_y,0,sizeof(vis_y));
        memset(board,0,sizeof(board));
        string tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            for(int j=0;j<n;j++){
                board[i][j+1] = ((tmp[j]=='#')?1:0);
            }
        }
        cout<<dfs(1,0)<<endl;
    }

    return 0;
}