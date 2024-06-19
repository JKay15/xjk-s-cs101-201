//这题想到将数组换成Si-520i是一个很巧妙的思路，这样就可用字典了
//其次是前缀和数组的下标问题，最好不要把实际的数从0开始存，这样会导致要求l-r的和，总是需要用presum[r]-presum[l-1]很别扭，边界条件会比较繁琐
//我后期都在修边界条件
//但我感觉一开始的o(n^2)也还不错，但是显然不如这个快了
#include <bits/stdc++.h>
using namespace std;
int n,t,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> presum(n+1);
    unordered_map<int,pair<int,int>> check;
    check[0]={0,0};
    presum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        presum[i]=presum[i-1]+t;
        int x=presum[i]-520*i;
        if(check.find(x)!=check.end()){
            if(i>check[x].second)check[x].second=i;
        }else check[x]={i,i};
    }
    for(auto x:check){
        auto t=x.second;
        ans=max(ans,(presum[t.second]-presum[t.first]));
    }
    cout<<ans;
}