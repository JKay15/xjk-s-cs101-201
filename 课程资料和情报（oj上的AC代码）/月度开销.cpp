#include <bits/stdc++.h>
using namespace std;
int n,m;
bool check(int x,vector<int> & a){
    int cnt=0,cum=0;
    for(int i=0;i<n;i++){
        if(cum+a[i]>x){
            cnt++;
            cum=a[i];
        }else{
            cum+=a[i];
            if(i==n-1)cnt++;
        } 
    }
    return (cnt>m)?0:1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> cost(n);
    for(int i=0;i<n;i++)cin>>cost[i];
    int r=accumulate(cost.begin(),cost.end(),0),res=0;
    int l=*max_element(cost.begin(),cost.end());
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,cost)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<"\n";
    return 0;
}