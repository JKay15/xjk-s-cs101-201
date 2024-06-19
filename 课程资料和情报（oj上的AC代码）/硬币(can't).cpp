//尝试动态规划，背包问题的变种，我没看出来啊阿啊
#include <bits/stdc++.h>
using namespace std;
int n,x,a[205];
int dp[10005],res[10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    for(int j=x;j>=a[i];j--)
        dp[j]+=dp[j-a[i]];
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j<a[i])
                res[j]=dp[j];
            else    
                res[j]=dp[j]-res[j-a[i]];
        }
        if(!res[x])ans.push_back(a[i]);
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)cout<<x<<" ";
    return 0;
}
//暴力法，不行
// unordered_map<int,int> lis;
// int total,n,x,a[205];
// void dfs(vector<int> used,int i,int t){
//     if(i>n||t==x){
//         if(t==x){
//             for(auto x:used)lis[x]++;
//             total++;
//         }
//         return ;
//     }
//     dfs(used,i+1,t);
//     if(t+a[i]<=x){
//         used.push_back(i);
//         dfs(used,i+1,t+a[i]);
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>x;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs({},1,0);
//     vector<int> must;
//     int num=0;
//     for(auto [x,y]:lis){
//         if(y==total){
//             num++;
//             must.push_back(a[x]);
//         }
//     }
//     sort(must.begin(),must.end());
//     cout<<num<<"\n";
//     for(auto x:must)cout<<x<<" ";
//     return 0;
// }