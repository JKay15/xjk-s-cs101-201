#include <bits/stdc++.h>
using namespace std;
long long m,s,c,ans;
priority_queue<int> q;
int main(){
    cin>>m>>s>>c;
    ans=m;
    vector<int> tmp(c);
    for(int i=0;i<c;i++)cin>>tmp[i];
    sort(tmp.begin(),tmp.end());
    if(m>=c){cout<<c;return 0;}
    for(int i=1;i<c;i++){q.push(tmp[i]-tmp[i-1]);ans+=(tmp[i]-tmp[i-1]);}
    for(int i=1;i<m;i++){ans-=q.top();q.pop();}
    cout<<ans;
    return 0;
}