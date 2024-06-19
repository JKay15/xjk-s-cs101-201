#include<bits/stdc++.h>
using namespace std;
int n,m,c,mod=65536;
char x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    while(m--){
        cin>>x>>c;
        if(x=='C')for(auto& y:num)y=(y+c)%mod;
        else cout<<accumulate(num.begin(),num.end(),0,[](int acc,int x){return acc+bool(x&(1<<c));})<<"\n";
    }
    return 0;
}