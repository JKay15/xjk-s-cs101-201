#include <bits/stdc++.h>
using namespace std;
int m,n,tree[21][21],pre[21][21],ans;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
        cin>>tree[i][j];
        pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+tree[i][j];
        for(int k=1;k<=i;k++)
        for(int p=1;p<=j;p++)if(!(pre[i][j]-pre[k-1][j]-pre[i][p-1]+pre[k-1][p-1]))ans=max(ans,(i-k+1)*(j-p+1));
    }
    cout<<ans;
    return 0;
}