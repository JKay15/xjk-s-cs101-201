#include <bits/stdc++.h>
using namespace std;
int n,dp[50];
int main(){
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[a[1]]=dp[0]=1;
    for(int i=2;i<=n;i++)
    for(int j=40;j>=1;j--)dp[j]+=(j>=a[i])?dp[j-a[i]]:0;
    cout<<dp[40]<<"\n";
    return 0;
}