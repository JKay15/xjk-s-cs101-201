#include <bits/stdc++.h>
using namespace std;
int n,cur;
inline bool check(pair<int,int>& x,pair<int,int> &y){
    return ((x.first>y.first&&x.second>=y.second)||(x.first>=y.first&&x.second>y.second));
}
bool comp(pair<int,int>& x,pair<int,int> &y){
    if(check(x,y))return 1;
    if((x.first<y.first&&x.second<=y.second)||(x.first<=y.first&&x.second<y.second))return 0;
    if(x.first<y.first||(x.first==y.first&&x.second<=y.second))return 1;
    return 0;
}

void out1(vector<int>& ans,vector<pair<int,int>>& cont){
    cout<<ans.size()<<":";
    for(auto x:ans)cout<<" ("<<cont[x].first<<","<<cont[x].second<<")";
    cout<<"\n";
    ans.clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<pair<int,int> > cont(n);
    for(int i=0;i<n;i++)cin>>cont[i].first>>cont[i].second;
    sort(cont.begin(),cont.end(),comp);
    vector<int> ans;
    ans.push_back(0);
    for(int i=1;i<n;i++){
        if(check(cont[i-1],cont[i]))out1(ans,cont);
        ans.push_back(i);
    }
    if(ans.size())out1(ans,cont);
    return 0;
}