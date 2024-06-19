//除了前缀和之外，也是可以用动态规划做的
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> mat[n],presum[n];
    for(int i=0;i<n;i++){
        mat[i].resize(n);
        presum[i].resize(n);
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>mat[i][j];
    presum[0][0]=mat[0][0];
    for(int i=1;i<n;i++){
        presum[0][i]=presum[0][i-1]+mat[0][i];
        presum[i][0]=presum[i-1][0]+mat[i][0];
    }
    for(int i=1;i<n;i++)
    for(int j=1;j<n;j++)presum[i][j]=mat[i][j]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
    int ans=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        for(int k=i;k<n;k++)
        for(int l=j;l<n;l++){
            ans=max(ans,presum[k][l]-((i)?presum[i-1][l]:0)-((j)?presum[k][j-1]:0)+((!i||!j)?0:presum[i-1][j-1]));
        }
    }
    cout<<ans;
    return 0;
}