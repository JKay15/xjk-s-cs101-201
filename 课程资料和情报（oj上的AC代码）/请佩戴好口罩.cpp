#include<bits/stdc++.h>
using namespace std;
int n,cx,cy,d;
bool wear[105][105];
#define check(x,y) (x>=0&&x<n&&y>=0&&y<n)
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int ans[2][105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>wear[i][j];
    cin>>cx>>cy;
    ans[0][cx][cy]=1;
    cin>>d;
    for(int k=1;k<=d;k++){
        int cur=(k%2)?0:1;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(ans[cur][i][j]&&!wear[i][j]){
                ans[!cur][i][j]=1;
                for(int p=0;p<4;p++){
                    int xx=i+dx[p],yy=j+dy[p];
                    if(check(xx,yy)&&!wear[xx][yy])ans[!cur][xx][yy]=1;
                }
            }else if(ans[cur][i][j]&&wear[i][j])ans[!cur][i][j]=1;
            else if(wear[i][j]){
                int tt=0;
                for(int p=0;p<4;p++){
                    int xx=i+dx[p],yy=j+dy[p];
                    if(check(xx,yy)&&ans[cur][xx][yy])tt++;
                }
                if(tt==4)ans[!cur][i][j]=1;
            }
        }
    }
    int cur=((d+1)%2)?0:1;
    int res=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    res+=ans[cur][i][j];
    cout<<res;
    return 0;
}