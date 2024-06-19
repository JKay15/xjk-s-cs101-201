//二部图，找分类标准，枚举就好，相同高度的不用重复枚举
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        if(a[1]==a[n]){
            cout<<n/2<<"\n";
            continue;
        }
        ll ans=0;
        for(int l=1,r=1;l<=n;l=r=r+1){
            while(r+1<=n&&a[r+1]==a[l])++r;
            ans=max(ans,1ll*(n-r)*r);
        }
        cout<<ans<<"\n";
    }
    return 0;
}