#include <bits/stdc++.h>
using namespace std;
int t,x;
vector<int> dp;
int gap(int a,int b){
    return abs(t-a-b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(cin>>x)dp.push_back(x);
    sort(dp.begin(),dp.end());
    int l=0,r=dp.size()-1,ans=0x7777777;
    while(l<r){
        while(l<r&&dp[l]+dp[r]>=t){
            if(gap(dp[l],dp[r])<abs(ans-t))ans=dp[l]+dp[r];
            else if(gap(dp[l],dp[r])==abs(ans-t))ans=min(ans,dp[l]+dp[r]);
            r--;
        }
        if(l<r&&gap(dp[l],dp[r])<abs(ans-t))ans=dp[l]+dp[r];
        else if(l<r&&gap(dp[l],dp[r])==abs(ans-t))ans=min(ans,dp[l]+dp[r]);
        l++;
    }
    cout<<ans;
    return 0;
}