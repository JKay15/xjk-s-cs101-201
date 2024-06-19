#include <bits/stdc++.h>
using namespace std;
vector<array<int,3>> a;
inline double dis(int x,int y){
    double ans=0;
    for(int i=0;i<3;i++)ans+=(a[x][i]-a[y][i])*(a[x][i]-a[y][i]);
    return sqrt(ans);
}
struct node{
    int l,r;
    double d;
    node(int x=0,int y=0):l(x),r(y){
        d=dis(l,r);
    }
    bool operator<(const node&x)const{
        if(d==x.d){
            if(l==x.l)return r<x.r;
            return l<x.l;
        }
        return d>x.d;
    }
};
int main(){
    int n;
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;i++)for(int j=0;j<3;j++)scanf("%d",&a[i][j]);
    vector<node> ans;
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)ans.push_back({i,j});
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        printf("(%d",a[x.l][0]);
        for(int i=1;i<3;i++)printf(",%d",a[x.l][i]);
        printf(")-(%d",a[x.r][0]);
        for(int i=1;i<3;i++)printf(",%d",a[x.r][i]);
        printf(")=%.2f\n",x.d);
    }
    return 0;
}