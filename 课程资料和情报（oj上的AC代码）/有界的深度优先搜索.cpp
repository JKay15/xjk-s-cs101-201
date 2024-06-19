//无向图建图的时候记得要加双向边啊，这里挂了就很傻逼
#include <bits/stdc++.h>
using namespace std;
int n,m,l,s,t1,t2,vis[105];
vector<int> mat[105];
string ans;
void dfs(int x,int d){
    ans+=to_string(x)+" ";
    sort(mat[x].begin(),mat[x].end());
    for(auto y:mat[x]){
        if(!vis[y]){
            vis[y]=1;
            if(d<l)dfs(y,d+1);
            else ans+=to_string(y)+" ";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>l;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        mat[t1].push_back(t2);
        mat[t2].push_back(t1);
    }
    cin>>s;
    vis[s]=1;
    dfs(s,1);
    cout<<ans;
    return 0;
}