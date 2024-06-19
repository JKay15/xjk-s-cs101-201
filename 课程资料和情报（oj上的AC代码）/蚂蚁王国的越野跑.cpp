//忘了归并怎么写了。。。。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int n,a[100005];
void merge(int l,int mid,int r){
    int *b=new int[r-l+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            b[k++]=a[i++];
            ans+=r-j+1;
        }
        else b[k++]=a[j++];
    }
    while(i<=mid)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    k=0;
    for(i=l;i<=r;i++)a[i]=b[k++];
    delete[] b;
}
void mergesort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    mergesort(0,n-1);
    cout<<ans<<"\n";
    return 0;
}