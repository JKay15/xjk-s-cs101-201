#include <bits/stdc++.h>
using namespace std;
int n,m,pos[100005];
int check(int x){
    int num=1,cur=0;
    for(int i=1;i<n;i++){
        if(pos[i]-pos[cur]>=x){
            num++;
            cur=i;
        }
    }
    return num>=m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>pos[i];
    sort(pos,pos+n);
    int l=1,r=pos[n-1]-pos[0],res=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res;
    return 0;
}