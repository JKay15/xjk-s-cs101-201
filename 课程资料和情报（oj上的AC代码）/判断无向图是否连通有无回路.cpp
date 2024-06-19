#include <bits/stdc++.h>
using namespace std;
int n,m,t1,t2,vis[110],ans,tot=1;
vector<int> edge[110];
bool check(int t,int from){
    if(tot==n)return 1;
    for(auto x:edge[t]){
        if(!vis[x]){
            tot++;
            vis[x]=1;
            check(x,t);
        }else if(from!=x)ans=1;
    }
    if(tot==n)return 1;
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    vis[0]=1;
    cout<<"connected:"<<((check(0,-1))?"yes":"no")<<"\n";
    for(int i=1;i<n;i++){
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        check(i,-1);
    }
    cout<<"loop:"<<((ans)?"yes":"no");
    return 0;
}