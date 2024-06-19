#include <bits/stdc++.h>
using namespace std;
int vis[1001];
int weight[6]={1,2,3,5,10,20};
int num[6];
int total;
void solve(int n,int sum){
    if(n>5){
        if(!vis[sum]&&sum){
            total++;
            vis[sum]=1;
        }
        return ;
    }
    for(int i=0;i<=num[n];i++)
        solve(n+1,sum+i*weight[n]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<6;i++)
        cin>>num[i];
    solve(0,0);
    cout<<"Total="<<total<<endl;
    return 0;
}