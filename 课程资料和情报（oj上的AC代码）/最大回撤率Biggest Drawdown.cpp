//最大回撤的定义都没说清楚，纯靠猜了
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<double> r,t;
    vector<pair<double,int>> mmin;
    string tmp;
    while(cin>>tmp)r.push_back(stod(tmp));
    int l=r.size();
    t.push_back(1+r[0]/100);
    for(int i=1;i<l;i++)t.push_back(1.0*t[i-1]*(1+r[i]/100));
    mmin.push_back({t[l-1],l-1});
    for(int i=1;i<l;i++){
        if(t[l-i-1]<mmin[i-1].first)mmin.push_back({t[l-i-1],l-i-1});
        else mmin.push_back(mmin[i-1]);
    }
    double ans=0;int pos=0;
    for(int i=0;i<l-1;i++){
        if(ans<(1.0*(t[i]-mmin[l-i-1].first)/t[i])){
            ans=(1.0*(t[i]-mmin[l-i-1].first)/t[i]);
            pos=mmin[l-i-1].second-i;
        }
    }
    printf("%.1f",-1.0*ans*100);cout<<"% "<<pos;
    return 0;
}