#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    deque<int> mmax,mmin,a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<k;i++){
        while(!mmax.empty()&&a[i]>=a[mmax.back()])mmax.pop_back();
        while(!mmin.empty()&&a[i]<=a[mmin.back()])mmin.pop_back();
        mmax.push_back(i);mmin.push_back(i);
    }
    cout<<a[mmin[0]]<<" ";
    for(int i=k;i<n;i++){
        while(!mmin.empty()&&mmin[0]<=i-k)mmin.pop_front();
        while(!mmin.empty()&&a[i]<=a[mmin.back()])mmin.pop_back();
        mmin.push_back(i);
        cout<<a[mmin[0]]<<" ";
    }
    cout<<"\n"<<a[mmax[0]]<<" ";
    for(int i=k;i<n;i++){
        while(!mmax.empty()&&mmax[0]<=i-k)mmax.pop_front();
        while(!mmax.empty()&&a[i]>=a[mmax.back()])mmax.pop_back();
        mmax.push_back(i);
        cout<<a[mmax[0]]<<" ";
    }
    return 0;
}