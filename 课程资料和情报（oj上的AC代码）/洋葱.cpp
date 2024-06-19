#include <bits/stdc++.h>
using namespace std;
int n,mat[105][105],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>mat[i][j];
    if(n%2)ans=mat[(n+1)/2][(n+1)/2];
    for(int i=1;i<=(n+1)/2;i++){
        int tot=0;
        for(int j=i;j<=n-i;j++)tot+=mat[i][j]+mat[j][n-i+1]+mat[n-i+1][n-j+1]+mat[n-j+1][i];
        ans=max(ans,tot);
    }
    cout<<ans;
    return 0;
}