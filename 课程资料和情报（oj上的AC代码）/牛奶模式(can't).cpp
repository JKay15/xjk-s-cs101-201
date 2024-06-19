//感觉差了很多模版。。。

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=100010,K1=10007;
int s[N],Rank[N];
ull K[N],H[N],Hash[N];
int n,k;
bool cmp(const int& __x,const int& __y){
    return Hash[__x]<Hash[__y]||(Hash[__x]==Hash[__y]&&__x<__y);
}
bool chk(int len){
    int c=0;
    for(int i=0;i<n-len+1;++i){
        Rank[i]=i;
        Hash[i]=H[i]-H[i+len]*K[len];
    }
    sort(Rank,Rank+n-len+1,cmp);
    for(int i=0;i<n-len+1;++i){
        if(i==0||Hash[Rank[i]]!=Hash[Rank[i-1]])c=0;
        if(++c>=k)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>s[i];
    H[n]=0;for(int i=n-1;i>=0;--i)H[i]=H[i+1]*K1+s[i];
    K[0]=1;for(int i=1;i<=n;++i)K[i]=K[i-1]*K1;
    int l=1,r=n+1;
    while(r-l>1){
        int m=l+r>>1;
        if(chk(m))l=m;
        else r=m;
    }
    cout<<l<<endl;
}