#include <bits/stdc++.h>
using namespace std;
int n,a[20005];
int merge(int l,int r){
    int l1=l,m=(l+r)>>1,l2=m+1,ans=0;
    vector<int> cont;
    while(l1<=m&&l2<=r){
        if(a[l1]<=a[l2])cont.push_back(a[l1++]);
        else{
            ans+=m-l1+1;
            cont.push_back(a[l2++]);
        }
    }
    while(l1<=m)cont.push_back(a[l1++]);
    while(l2<=r)cont.push_back(a[l2++]);
    for(int i=l,j=0;i<=r;i++)a[i]=cont[j++];
    return ans;
}
int solve(int l,int r){
    if(l>=r)return 0;
    int mid=(l+r)>>1;
    int l1=solve(l,mid);
    int l2=solve(mid+1,r);
    return l1+l2+merge(l,r);
}
int main(){
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        printf("%d\n",solve(0,n-1));
    }
    return 0;
}