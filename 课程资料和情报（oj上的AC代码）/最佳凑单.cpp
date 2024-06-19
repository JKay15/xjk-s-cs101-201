#include <bits/stdc++.h>
using namespace std;
int n,t,price[105],ans=0x7777777;
unordered_set<int> mmap[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>t;
    for(int i=0;i<n;i++)cin>>price[i];
    mmap[0].insert(price[0]);
    mmap[0].insert(0);
    for(int i=1;i<n;i++){
        int mmin=0x7777777;
        for(auto x:mmap[i-1]){
            if(x>=t&&x-t<mmin-t)mmin=x;
            else{
                if(x+price[i]>=t&&x+price[i]-t<mmin-t)mmin=x+price[i];
                else if(x+price[i]<t)mmap[i].insert(x+price[i]);
                mmap[i].insert(x);
            }
        }
        if(i==n-1){cout<<((mmin==0x7777777)?0:mmin);return 0;}
        mmap[i].insert(mmin);
    }
    return 0;
}