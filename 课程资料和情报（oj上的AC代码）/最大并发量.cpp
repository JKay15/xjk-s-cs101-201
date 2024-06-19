#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> dic;
        set<int> time;
        vector<int>start(n),end(n);
        for(int i=0;i<n;i++){
            cin>>start[i]>>end[i];
            time.insert(start[i]);time.insert(end[i]);
        }
        int cur=1;
        for(auto x:time)dic.insert({x,cur++});
        vector<int> use(cur+1);
        for(int i=0;i<n;i++){
            int s=dic[start[i]],e=dic[end[i]];
            for(int j=s;j<e;j++)use[j]++;
        }
        cout<<(*max_element(use.begin(),use.end()))<<"\n";
    }
    return 0;
}