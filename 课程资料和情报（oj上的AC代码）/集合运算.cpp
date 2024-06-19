#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++)cin>>b[i];
    sort(b.begin(),b.end());
    vector<int> inner(min(m,n)),ans(m+n),tmp(m+n);
    inner.erase(set_intersection(a.begin(),a.end(),b.begin(),b.end(),inner.begin()),inner.end());
    tmp.erase(set_union(a.begin(),a.end(),b.begin(),b.end(),tmp.begin()),tmp.end());
    ans.erase(set_difference(tmp.begin(),tmp.end(),inner.begin(),inner.end(),ans.begin()),ans.end());
    for(auto x:ans)cout<<x<<" ";
    return 0;
}