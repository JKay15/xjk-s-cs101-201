#include <bits/stdc++.h>
using namespace std;
int n,c;
int check(int x,vector<int> &stalls){
    int pos=1,cur=0;
    for(int i=2;i<=c;i++){
        if(pos>=n)return 0;
        while(stalls[pos]-stalls[cur]<x){
            pos++;
            if(pos>=n)return 0;
        }
        if(pos>=n)return 0;
        cur=pos;
        pos++;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    vector<int> stalls(n);
    for(int i=0;i<n;i++)cin>>stalls[i];
    sort(stalls.begin(),stalls.end());
    int l=0x7777777,r=0;
    for_each(stalls.begin(),stalls.end(),[&r,&l](int x){r=max(r,x);l=min(l,x);});
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,stalls)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res<<"\n";
    return 0;
}