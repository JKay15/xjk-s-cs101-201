#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
int vis[100][25];
int total;
int dx[3]={0,1,-1};
int dy[3]={1,0,0};
void dfs(int num,int x,int y){
    if(num==0){
        total++;
        return ;
    }
    for(int i=0;i<3;i++){
        if(!vis[x+dx[i]][y+dy[i]]){
            vis[x+dx[i]][y+dy[i]]=1;
            dfs(num-1,x+dx[i],y+dy[i]);
            vis[x+dx[i]][y+dy[i]]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vis[24][0]=1;
    dfs(n,24,0);
    cout<<total<<endl;
    return 0;
}