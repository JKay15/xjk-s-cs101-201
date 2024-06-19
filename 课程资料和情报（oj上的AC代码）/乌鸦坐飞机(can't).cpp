#include <bits/stdc++.h>
using namespace std;
int n,k,i,tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    vector<int> a(k);
    for(;i<k;i++)cin>>a[i];
    int x=n*2,y=n;
    for(i=0;i<k;i++){
        tmp=min(y,a[i]/4);
        y-=tmp;
        a[i]-=tmp*4;
    }
    x+=y;
    for(i=0;i<k;i++){
        tmp=min(x,a[i]/2);
        x-=tmp;
        a[i]-=tmp*2;
    }
    if(accumulate(a.begin(),a.end(),0)<=x+y)cout<<"YES";
    else cout<<"NO";
    return 0;
}