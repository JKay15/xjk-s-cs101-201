//从左往右尝试+背包提供额外信息就好了
//一开始想要用set存下左右的力矩，后来优化成了左右力矩之差，但是发现set只能判断能否平衡，不能记录次数，就不知道咋做了
//实际上优化成map就好，用数组也可以啊
//这个没办法压缩空间，因为不一定都需要前面或者后面的j，一定是两者都需要
#include <bits/stdc++.h>
using namespace std;
int c,g,d[25],w[25];
unordered_map<int,int> dp;
int main(){
    cin>>c>>g;
    for(int i=1;i<=c;i++)cin>>d[i];
    for(int i=1;i<=g;i++)cin>>w[i];
    dp.insert({7500,1});
    for(int i=1;i<=g;i++){
        unordered_map<int,int> tmp;
        for(auto x:dp)for(int j=1;j<=c;j++)tmp[x.first+w[i]*d[j]]+=x.second;
        dp=tmp;
    }
    cout<<dp[7500];
}
// #include <bits/stdc++.h>
// using namespace std;
// int g,c,d[25],w[25],dp[25][15010];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>c>>g;
//     for(int i=1;i<=c;i++)cin>>d[i];
//     for(int i=1;i<=g;i++)cin>>w[i];
//     dp[0][7500]=1;
//     for(int i=1;i<=g;i++)
//     for(int j=1;j<=15010;j++)
//     if(dp[i-1][j])for(int k=1;k<=c;k++)dp[i][j+w[i]*d[k]]+=dp[i-1][j];
//     cout<<dp[g][7500];
//     return 0;
// }