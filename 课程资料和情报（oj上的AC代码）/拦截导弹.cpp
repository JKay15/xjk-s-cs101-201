#include <bits/stdc++.h>
using namespace std;
int k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k;
    vector<int> h(k),dp;
    for(int i=0;i<k;i++)cin>>h[i];
    dp.assign(k,1);
    for(int i=1;i<k;i++)
    for(int j=0;j<i;j++)if(h[j]>=h[i])dp[i]=max(dp[i],dp[j]+1);
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}