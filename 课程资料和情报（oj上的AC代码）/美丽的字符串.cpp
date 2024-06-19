#include <bits/stdc++.h>
using namespace std;
string tmp;
char tt[3]={'a','b','c'};
int l;
bool dfs(int i){
    if(i==l)return 1;
    if(i==0&&tmp[i]!='?')return dfs(1);
    if(tmp[i]!='?')return (tmp[i]==tmp[i-1])?0:dfs(i+1);
    int ans=0;
    for(int j=0;j<3;j++){
        tmp[i]=tt[j];
        ans|=dfs(i+1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        cin>>tmp;
        l=tmp.length();
        cout<<((dfs(0))?"YES":"NO")<<"\n";
    }
    return 0;
}