#include <bits/stdc++.h>
using namespace std;
int n,num[500005];
long long ans;
//虽然知道了这道题是归并模版题，但是我并没有看出来为什么
//这似乎是一道错题，因为样例中的数据用冒泡都能实现更少的交换次数，很诡异——看错题了，是要升序，我以为是降序
//嗯，冒泡超时了，说明大概交换次数上，这俩是一样的，但是冒泡要算出这个次数，太慢了，归并可以加速
void merge(int l,int r){
    int cl=l,m=(l+r)>>1,cr=m+1;
    vector<int> cont;
    while(cl<=m&&cr<=r){
        if(num[cl]<=num[cr])cont.push_back(num[cl++]);
        else{
            ans+=m-cl+1;
            cont.push_back(num[cr++]);
        }
    }
    while(cl<=m)cont.push_back(num[cl++]);
    while(cr<=r)cont.push_back(num[cr++]);
    for(int i=l,j=0;i<=r;i++,j++)num[i]=cont[j];
}
void sorting(int l,int r){
    if(l>=r)return;
    int m=(l+r)>>1;
    sorting(l,m);
    sorting(m+1,r);
    merge(l,r);
}
void maopao(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(num[j]>num[j+1]){
                ans++;
                swap(num[j],num[j+1]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        ans=0;
        for(int i=0;i<n;i++)cin>>num[i];
        sorting(0,n-1);
        // maopao();
        cout<<ans<<"\n";
    }
    return 0;
}