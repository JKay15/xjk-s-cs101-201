//第一次尝试，超时
// #include <bits/stdc++.h>
// using namespace std;
// int n,ans=0x7777777;
// vector<int> mat[7];
// void dfs(int i){
//     if(i>=7){
//         int mmax=-0x7777777;
//         for(int j=0;j<n;j++){
//             int tot=0;
//             for(int i=0;i<n;i++)tot+=mat[i][j];
//             mmax=max(mmax,tot);
//         }
//         ans=min(ans,mmax);
//         return ;
//     }
//     do{
//         dfs(i+1);
//     }while(next_permutation(mat[i].begin(),mat[i].end()));
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>n&&n>0){
//         ans=0x7777777;
//         for(int i=0;i<n;i++){
//             mat[i].resize(n);
//             for(int j=0;j<n;j++)cin>>mat[i][j];
//             sort(mat[i].begin(),mat[i].end());
//         }
//         dfs(0);
//         cout<<ans<<"\n";
//     }
//     return 0;
// }
//这个是错的，无法保证最大值
// #include <bits/stdc++.h>
// using namespace std;
// int n,ans;
// int main(){
//     while(cin>>n&&n!=-1){
//         ans=0x7777777;
//         vector<int> order(n),mat[n];
//         for(int i=0;i<n;i++){
//             order[i]=i;
//             mat[i].resize(n);
//             for(int j=0;j<n;j++)cin>>mat[i][j];
//             sort(mat[i].begin(),mat[i].end());
//         }
//         do{
//             int mmax=0;
//             for(int i=0;i<n;i++)mmax+=mat[i][order[i]];
//             ans=min(ans,mmax);
//         }while(next_permutation(order.begin(),order.end()));
//         cout<<ans<<"\n";
//     }
// }
//dfs把矩阵放进参数会快吗？不知道为啥
#include <bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> mat[7];
void nexxt(int x){
    int tmp=mat[x][n-1];
    for(int i=n-1;i>0;i--)mat[x][i]=mat[x][i-1];
    mat[x][0]=tmp;
}
void dfs(int i){
    if(i>=n){
        int mmax=-0x7777777;
        for(int j=0;j<n;j++){
            int tot=0;
            for(int k=0;k<n;k++)tot+=mat[k][j];
            mmax=max(mmax,tot);
        }
        ans=min(ans,mmax);
        return ;
    }
    for(int j=0;j<=n;j++){
        nexxt(i);
        dfs(i+1);
    }
}
int main(){
    while(scanf("%d",&n)&&n>0){
        ans=0x7777777;
        for(int i=0;i<n;i++){
            mat[i].resize(n);
            for(int j=0;j<n;j++)scanf("%d",&mat[i][j]);
        }
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}