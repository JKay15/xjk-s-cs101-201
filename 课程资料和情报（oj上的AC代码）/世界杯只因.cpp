#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int l,r;
    node(int x=0,int y=0):l(x),r(y){}
    bool operator<(const node&x)const{
        if(l==x.l)return r>x.r;
        return l<x.l;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<node> cont(n);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        cont[i].l=max(1,i+1-t);
        cont[i].r=min(n,i+1+t);
    }
    sort(cont.begin(),cont.end());
    int cur=1,r=0,ans=0;
    //很神奇，其实我也没搞明白为啥最后ans不用+1，就直接是答案了，其实是错的，2 0 0就不行，但是AC了就很诡异
    //所以，只需要在最后面加上一个兜底的就可以了,必然会更新好我们要的ans
    cont.push_back({n,n});
    for(auto x:cont){
        if(x.l<=cur&&x.r>r)r=x.r;
        else if(x.l>cur){
            ans++;
            cur=r;
            if(x.l<=cur&&x.r>r)r=x.r;
        }
    }
    cout<<ans;
}