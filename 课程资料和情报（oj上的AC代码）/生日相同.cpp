//题目很傻逼，不说清楚必须要这个生日有两个人及以上才输出。。。。
#include <bits/stdc++.h>
using namespace std;
map<int,vector<string>> dic;
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        int t1,t2;
        cin>>tmp>>t1>>t2;
        dic[32*t1+t2].push_back(tmp);
    }
    for(auto [x,y]:dic){
        if(y.size()>1){
            cout<<x/32<<" "<<x%32;
            for(auto z:y)cout<<" "<<z;
            cout<<"\n";
        }
    }
    return 0;
}