#include <bits/stdc++.h>
using namespace std;
int n,t,t1,cw;
struct node{
int w,c;
bool operator<(const node&x)const{
    if(w==x.w)return c<x.c;
    return w>x.w;
}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<node> c(n);
    for(int i=0;i<n;i++)cin>>c[i].c>>c[i].w;
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        t1+=c[i].c;
        t=max(t,t1+c[i].w);
    }
    cout<<t;
    return 0;
}