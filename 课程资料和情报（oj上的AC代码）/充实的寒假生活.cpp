#include <bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool operator<(const node& x)const{
        if(r==x.r)return l>x.l;
        return r<x.r;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<node> s(n);
    for(int i=0;i<n;i++)cin>>s[i].l>>s[i].r;
    sort(s.begin(),s.end());
    int cur=-1,ans=0;
    for(int i=0;i<n;i++){
        if(s[i].l>cur){
            ans++;
            cur=s[i].r;
        }
    }
    cout<<ans;
    return 0;
}