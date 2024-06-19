#include<bits/stdc++.h>
using namespace std;
set<int> ans;
deque<int> a;
int n,k,p;
void shuff(){
    a.pop_front();
    for(int i=0;i<p;i++){
        a.push_back(a.front());
        a.pop_front();
    }
}
int main(){
    cin>>n>>k>>p;
    for(int i=1;i<=k;i++)a.push_back(i);
    while(!a.empty()){
        for(int i=1;i<n;i++)shuff();
        ans.insert(a.front());
        shuff();
    }
    for(auto x:ans)cout<<x<<"\n";
    return 0;
}