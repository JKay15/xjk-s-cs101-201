#include <bits/stdc++.h>
using namespace std;
int best[15];
int dfs4(int x){
    if(x==1)return 1;
    if(best[x])return best[x];
    int tmp=0x7777777;
    for(int k=1;k<x;k++)tmp=min(tmp,2*dfs4(x-k)+(1<<k)-1);
    return best[x]=tmp;
}
int main(){
    for(int i=1;i<=12;i++)cout<<dfs4(i)<<"\n";
    return 0;
}