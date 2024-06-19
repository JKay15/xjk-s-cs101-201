#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int l,r;
};
bool comp(const node&x,const node&y){
    if(x.r==y.r)return x.l<y.l;
    return x.r<y.r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        vector<node> a(n);
        for(int i=0;i<n;i++)cin>>a[i].l>>a[i].r;
        sort(a.begin(),a.end(),comp);
        int ans=0,cur=0;
        for(int i=0;i<n;i++){
            if(a[i].l>=cur){
                ans++;
                cur=a[i].r;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}