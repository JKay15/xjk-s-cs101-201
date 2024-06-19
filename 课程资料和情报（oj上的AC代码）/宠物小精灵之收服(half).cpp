//想复杂了，实际上就是普通的背包稍微转化了一点点
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005,maxm=505,maxk=105;
int dp[2][maxn][maxm][2],n,m,k,b[maxk],c[maxk];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)cin>>b[i]>>c[i];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(j>=b[i]&&p>=c[i]){
                    if(dp[0][j][p][0]<dp[0][j-b[i]][p-c[i]][0]+1){
                        dp[1][j][p][0]=dp[0][j-b[i]][p-c[i]][0]+1;
                        dp[1][j][p][1]=dp[0][j-b[i]][p-c[i]][1]+c[i];
                    }else if(dp[0][j][p][0]==dp[0][j-b[i]][p-c[i]][0]+1){
                        dp[1][j][p][1]=min(dp[0][j][p][1],dp[0][j-b[i]][p-c[i]][1]+c[i]);
                        dp[1][j][p][0]=dp[0][j][p][0];
                    }else{
                        dp[1][j][p][0]=dp[0][j][p][0];
                        dp[1][j][p][1]=dp[0][j][p][1];
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                dp[0][j][p][0]=dp[1][j][p][0];
                dp[0][j][p][1]=dp[1][j][p][1];
            }
        }
    }
    int total=dp[0][n][m][0],hurt=dp[0][n][m][1];
    cout<<total<<" "<<m-hurt;
    return 0;
}