//剪枝还是不好想的
#include <bits/stdc++.h>
using namespace std;
int n,used[70],last;
bool dfs(vector<int>&s,int unuse,int l,int tar){
    if(!(unuse+l))return 1;
    l=(l==0)?tar:l;
    int start=(l==tar)?0:last+1;
    for(int i=start;i<n;i++){
        if(!used[i]&&s[i]<=l){
            if(i&&!used[i-1]&&s[i]==s[i-1])continue;
            used[i]=1;
            last=i;
            if(dfs(s,unuse-1,l-s[i],tar))return 1;
            else{
                used[i]=0;
                if(s[i]==l||l==tar)return 0;
            }
        }
    }
    return 0;
}
int solve(vector<int> &sticks){
    sort(sticks.begin(),sticks.end(),greater<int>());
    int r=accumulate(sticks.begin(),sticks.end(),0);
    for(int i=r/sticks[0];i>=2;i--){
        if(r%i)continue;
        else{
            memset(used,0,sizeof(used));
            last=0;
            if(dfs(sticks,n,r/i,r/i))return r/i;
        }
    }
    return r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        vector<int> sticks(n);
        for(int i=0;i<n;i++)cin>>sticks[i];
        cout<<solve(sticks)<<"\n";
    }
    return 0;
}