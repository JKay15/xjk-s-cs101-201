#include <bits/stdc++.h>
using namespace std;
#define INF 0x7777777
const int maxn=1005;
int dp[maxn];
string tmp;
bool check(int l,int r){
    while(l<=r){
        if(tmp[l]!=tmp[r])return 0;
        l++;r--;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(dp,INF,sizeof(dp));
        cin>>tmp;
        int l=tmp.length();
        tmp=" "+tmp;
        for(int i=1;i<=l;i++)
        for(int j=1;j<=i;j++)
            if(check(j,i)){
                if(j==1)dp[i]=0;
                else dp[i]=min(dp[i],dp[j-1]+1);
            }
        cout<<dp[l]<<"\n";
    }
    return 0;
}