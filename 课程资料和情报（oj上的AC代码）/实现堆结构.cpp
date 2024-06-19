//其实是偷懒了，应该要手写heap的
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t,tmp;
    cin>>t;
    while(t--){
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> q;
        while(n--){
            cin>>tmp;
            if(tmp==1){
                cin>>tmp;q.push(tmp);
            }else{
                cout<<q.top()<<"\n";q.pop();
            }
        }
    }
    return 0;
}