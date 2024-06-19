#include <bits/stdc++.h>
using namespace std;
int w,s;
struct metal{
    int n,v;
    friend bool operator<(const metal& x,const metal& y){
        return 1.0*x.v/x.n>1.0*y.v/y.n;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>w>>s;
        vector<metal> m(s);
        for(int i=0;i<s;i++)cin>>m[i].n>>m[i].v;
        sort(m.begin(),m.end());
        double res=0;
        for(auto x:m){
            if(w<x.n){
                res+=1.0*w*x.v/x.n;
                break;
            }else{
                res+=x.v;
                w-=x.n;
            }
            if(!w)break;
        }
        printf("%.2f\n",res);
    }
    return 0;
}