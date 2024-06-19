#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,f[65546];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    f[1]=1;
    for(int i=2;i<=65536;i++)f[i]=f[i-1]+log10(i)+1;
    vector<int> a(t),b(t);
    for(int i=0;i<t;i++)cin>>a[i];
    b=a;
    sort(a.begin(),a.end());
    map<int,int> ans;
    ll l=0,tmp=f[1],r=2;
    while(l<t){
        while(tmp<a[l])tmp+=f[r++];
        ll r1=1,where=a[l++]-(tmp-f[r-1]);
        while(f[r1]<where)r1++;
        int ans1=log10(r1)+1-where+f[r1-1];
        for(int i=0;i<ans1;i++)r1/=10;
        ans[a[l-1]]=r1%10;
    }
    for(auto x:b)cout<<ans[x]<<"\n";
    return 0;
}