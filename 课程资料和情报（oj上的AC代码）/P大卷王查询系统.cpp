#include <bits/stdc++.h>
using namespace std;
unordered_map<string,pair<int,double> > lis;
int n,x,y,tmp3;
string tmp1,tmp2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
        cin>>tmp1>>tmp2>>tmp3;
        lis[tmp2].second=1.0*(lis[tmp2].second*lis[tmp2].first+tmp3)/(lis[tmp2].first+1);
        lis[tmp2].first++;
    }
    cin>>tmp3;
    for(int i=1;i<=tmp3;i++){
        cin>>tmp1;
        if(lis[tmp1].first>=x&&lis[tmp1].second>y)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}