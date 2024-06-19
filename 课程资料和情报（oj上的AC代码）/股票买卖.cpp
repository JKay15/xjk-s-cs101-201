//除了没有优化输入之外没啥缺点，但是容器容易产生混淆（因为两个过程放一起了），所以不利于理解
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,tmp,ans;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++)cin>>price[i];
        //至多以第i天结尾的最大收益
        vector<int> pre(n);
        int mmin=price[0],mmax=price[n-1];
        for(int i=1;i<n;i++){
            mmin=min(mmin,price[i]);
            pre[i]=max(pre[i-1],price[i]-mmin);
        }
        ans=pre[n-1];pre[n-1]=0;
        //至少以第i天开始的最大收益
        for(int i=n-2;i>=0;i--){
            mmax=max(mmax,price[i]);
            tmp=pre[i];
            pre[i]=max(pre[i+1],mmax-price[i]);
            ans=max(ans,tmp+pre[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//最初最好理解的版本
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> price(n);
//         for(int i=0;i<n;i++)cin>>price[i];
//         vector<int> pre(n),suf(n);
//         int mmin=price[0],mmax=price[n-1];
//         for(int i=1;i<n;i++){
//             mmin=min(mmin,price[i]);
//             pre[i]=max(pre[i-1],price[i]-mmin);
//         }
//         for(int i=n-2;i>=0;i--){
//             mmax=max(mmax,price[i]);
//             suf[i]=max(suf[i+1],mmax-price[i]);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++)ans=max(ans,pre[i]+suf[i]);
//         cout<<ans<<"\n";
//     }
//     return 0;
// }
//一个优化了输入的版本，可以大幅度降低时间
// #include<bits/stdc++.h>
// using namespace std;
// const int maxn=1e5+10,INF=1e7;
// int T,n,a[maxn],dd[maxn];
// int aa,ff;char cc;
// int read() {
//     aa=0;cc=getchar();ff=1;
//     while(cc<'0'||cc>'9') {
//         if(cc=='-') ff=-1;
//         cc=getchar();
//     }
//     while(cc>='0'&&cc<='9') aa=aa*10+cc-'0',cc=getchar();
//     return aa*ff;
// }
// int main() {
//     T=read(); int num,ans,maxnum;
//     while(T--) {
//         n=read();ans=0;num=INF;maxnum=0;
//         for(int i=1;i<=n;++i) {
//             a[i]=read();
//             num=min(num,a[i]);
//             dd[i]=max(a[i]-num,dd[i-1]);
//         }
//         num=-INF;
//         for(int i=n;i;--i) {
//             num=max(num,a[i]);
//             maxnum=max(maxnum,num-a[i]);
//             ans=max(ans,dd[i]+maxnum);
//         }
//         printf("%d\n",ans);
//     }
//     return 0;
// }