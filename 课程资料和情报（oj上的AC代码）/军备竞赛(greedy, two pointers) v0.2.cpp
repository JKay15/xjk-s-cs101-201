#include <bits/stdc++.h>
using namespace std;
int t,p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>p; 
    vector<int> price;
    while(cin>>t)price.push_back(t);
    sort(price.begin(),price.end());
    int l=-1,r=price.size();
    int n=r;
    while(1){
        while(p-price[l+1]<0&&l+1>n-r&&l+2<r){
            r--;
            p+=price[r];
        }
        if(p-price[l+1]>=0){
            l++;
            p-=price[l];
        }
        else break;
        if(l>r||l+1<n-r)break;
    }
    cout<<l+1-n+r;
    return 0;
}