#include <bits/stdc++.h>
using namespace std;
int n,dp[32],tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            vector<int> pos;
            int mmax=0;
            for(int j=0;j<32;j++){
                if(tmp&(1<<j)){
                    pos.push_back(j);
                    mmax=max(mmax,dp[j]);
                }
            }
            for(auto x:pos)dp[x]=mmax+1;
        }
        int ans=0;
        for(int i=0;i<32;i++)ans=max(ans,dp[i]);
        cout<<ans<<"\n";
    }
    return 0;
}