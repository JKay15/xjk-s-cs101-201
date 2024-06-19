//广搜，我一直在想能不能贪心。。。
#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,k,vis[maxn+5];
struct node{
    int x,step;
    node(int a,int b):x(a),step(b){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    queue<node>q;
    q.push({n,0}); 
    vis[n]=1;
    while(!q.empty()){
        node s=q.front();
        if(s.x==k){
            cout<<s.step<<"\n";
            return 0;
        }else{
            if(s.x-1>=0&&!vis[s.x-1]){
                q.push({s.x-1,s.step+1});
                vis[s.x-1]=1;
            }
            if(s.x+1<=maxn&&!vis[s.x+1]){
                q.push({s.x+1,s.step+1});
                vis[s.x+1]=1;
            }
            if((s.x<<1)<=maxn&&!vis[s.x<<1]){
                q.push({s.x<<1,s.step+1});
                vis[s.x<<1]=1;
            }
            q.pop();
        }
    }
    return 0;
}