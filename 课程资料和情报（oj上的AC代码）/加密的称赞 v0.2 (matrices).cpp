#include <bits/stdc++.h>
using namespace std;
int n,mat[105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>mat[i][j];
    string ans="";
    for(int i=1;i<=(n+1)/2;i++){
        int tag=0;
        for(int j=i;j<=n-i;j++){
            if(!mat[j][i]){
                tag=1;
                break;
            }
            ans+=char(mat[j][i]);
        }
        if(tag)break;
        for(int j=i;j<=n-i;j++){
            if(!mat[n-i+1][j]){
                tag=1;
                break;
            }
            ans+=char(mat[n-i+1][j]);
        }
        if(tag)break;
        for(int j=n-i+1;j>i;j--){
            if(!mat[j][n-i+1]){
                tag=1;
                break;
            }
            ans+=char(mat[j][n-i+1]);
        }
        if(tag)break;
        for(int j=n-i+1;j>i;j--){
            if(!mat[i][j]){
                tag=1;
                break;
            }
            ans+=char(mat[i][j]);
        }
        if(tag)break;
    }
    if(n%2&&mat[(n+1)/2][(n+1)/2])ans+=char(mat[(n+1)/2][(n+1)/2]);
    cout<<ans;
    return 0;
}