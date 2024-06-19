#include <bits/stdc++.h>
using namespace std;
int n;
struct cmp{
    bool operator()(int x,int y){
        return x>y;
    }
};
int main(){
    freopen("/Users/xiongjiangkai/Desktop/OJ18164-剪绳子/1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    priority_queue<int,vector<int>,cmp> line;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        line.push(t);
    }
    long long ans=0;
    while(line.size()>1){
        int t1=line.top();
        line.pop();
        int t2=line.top();
        line.pop();
        ans+=t1+t2;
        line.push(t1+t2);
    }
    cout<<ans;
    return 0;
}