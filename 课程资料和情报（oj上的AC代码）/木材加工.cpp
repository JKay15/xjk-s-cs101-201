#include <bits/stdc++.h>
using namespace std;
int n,k,res;
int l1[10005];
bool check(int x){
    int tot=0;
    for(int i=1;i<=n;i++)tot+=l1[i]/x;
    return (tot>=k)?1:0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int l=1,r=0,s=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        s+=l1[i];
        r=max(r,l1[i]);
    }
    r=min(r,s/k);
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