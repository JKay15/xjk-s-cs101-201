//状态压缩做不了，超过复杂度要求了——可以做，就是标准的状压，只是我傻了，没用位运算
#include<bits/stdc++.h>
using namespace std;
int dp[1<<18];
int w[101],v[101],n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k>>v[i];
        int tmp=0,t;
        for(int j=0;j<k;j++){
            cin>>t;
            tmp+=(1<<(t-1));
        }
        w[i]=tmp;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<18);j++){
            if(!(j&w[i])){
                int ww=j|w[i];
                dp[ww]=max(dp[ww],dp[j]+v[i]);
            }
        }
    }
    int ans=0;
    for(int j=0;j<(1<<18);j++)ans=max(ans,dp[j]);
    cout<<ans<<"\n";
    return 0;
}
//最短路是错的
// #include<bits/stdc++.h>
// using namespace std;
// int w[101],v[101],n,k;
// bool check(int x,int y){
//     for(int k=0;k<18;k++)if((x&(1<<k))&&(y&(1<<k)))return 0;
//     return 1;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>k>>v[i];
//         int tmp=0,t;
//         for(int j=0;j<k;j++){
//             cin>>t;
//             tmp+=(1<<(t-1));
//         }
//         w[i]=tmp;
//     }
//     int ans=0;
//     for(int i=0;i<n;i++){
//         int vis[101]={0};
//         vis[i]=1;
//         priority_queue<pair<int,int>> q;
//         q.push({v[i],w[i]});
//         while(q.size()){
//             auto cur=q.top();
//             q.pop();
//             ans=max(ans,cur.first);
//             for(int j=0;j<n;j++){
//                 if(!vis[j]&&check(w[j],cur.second)){
//                     vis[j]=1;
//                     q.push({cur.first+v[j],cur.second+w[j]});
//                 }
//             }
//         }
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
//并查集试一试
//pre[i]记录的是占用了i号日期的课程代表
//应该还是错的，因为一个课程会和所有有冲突的天数的课合并，这显然不对，比如一个课程占用了1、2两天，首先和所有占用了1的课程合并，之后和占用了2的课程合并就不对了
//因为占用了1的课程中可能存在没有占用2的，因此不应该合并，这个算法做出来的结果一定是偏小的。
// #include<bits/stdc++.h>
// using namespace std;
// int f[101],mmax[101],pre[20],vis[101],n;
// int findx(int x){
//     if(f[x]!=x)f[x]=findx(f[x]);
//     return f[x];
// }
// void uunion(int x,int y){
//     int fx=findx(x),fy=findx(y);
//     if(fx!=fy){
//         mmax[fx]=max(mmax[fx],mmax[fy]);
//         f[fy]=fx;
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)f[i]=i;
//     for(int i=1;i<=n;i++){
//         int k,tmp;
//         cin>>k>>mmax[i];
//         for(int j=0;j<k;j++){
//             cin>>tmp;
//             if(!pre[tmp])pre[tmp]=i;
//             else uunion(pre[tmp],i);
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=18;i++){
//         if(pre[i]){
//             int ff=findx(pre[i]);
//             if(!vis[ff])ans+=mmax[ff];
//             vis[ff]=1;
//         }
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
//dfs也是超时的
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> cont[20];
// int w[101],v[101],vis[101],n,k,ans;
// inline bool check(int x,int y){
//     for(int k=0;k<18;k++)if((x&(1<<k))&&(y&(1<<k)))return 0;
//     return 1;
// }
// void dfs(int i,int path,int mmax){
//     if(i>=18){
//         ans=max(ans,mmax);
//         return ;
//     }
//     for(auto x:cont[i]){
//         if(!vis[x]&&check(path,w[x])){
//             vis[x]=1;
//             dfs(i+1,path+w[x],mmax+v[x]);
//             vis[x]=0;
//         }
//     }
//     dfs(i+1,path,mmax);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>k>>v[i];
//         int tmp=0,t;
//         for(int j=0;j<k;j++){
//             cin>>t;
//             cont[t-1].push_back(i);
//             tmp+=(1<<(t-1));
//         }
//         w[i]=tmp;
//     }
//     dfs(0,0,0);
//     cout<<ans<<"\n";
//     return 0;
// }