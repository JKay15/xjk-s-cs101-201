#include <bits/stdc++.h>
using namespace std;
string tmp;
bool cmp(const pair<int,bool>&x,const pair<int,bool>&y){
    return x.first<y.first;
}
void solve(){
    vector<int> stack;
    vector<pair<int,bool>> prob;
    int l=tmp.length();
    for(int i=0;i<l;i++){
        if(tmp[i]=='(')stack.push_back(i);
        else if(tmp[i]==')'){
            if(stack.empty())prob.push_back({i,1});
            else stack.pop_back();
        }
    }
    for(auto x:stack)prob.push_back({x,0});
    int l1=prob.size();
    sort(prob.begin(),prob.end(),cmp);
    for(int i=0,j=0;i<l;i++){
        if(j<l1&&prob[j].first==i)cout<<((prob[j++].second)?'?':'$');
        else cout<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>tmp){
        cout<<tmp<<"\n";
        solve();
    }
    return 0;
}