#include <bits/stdc++.h>
using namespace std;
int m,n,x,y,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    vector<int> mat[m+5];
    for(int i=1;i<=m;i++){
        mat[i].resize(n+5);
        for(int j=1;j<=n;j++)cin>>mat[i][j];
    }
    cin>>x>>y;
    swap(mat[x],mat[y]);
    for(int i=2;i<=m-1;i++)ans+=(mat[i][1]+mat[i][n]);
    for(int i=1;i<=n;i++)ans+=(mat[1][i]+mat[m][i]);
    cout<<ans<<"\n";
    return 0;   
}