#include<iostream>
#include<algorithm>
using namespace std;
struct wood
{
    int len;
    int wid;
    int add;
};
bool cmp2(wood x,wood y)
{
    if(x.len==y.len)
        return x.wid<y.wid;
    else
        return x.len<y.len;
}
 
int main()
{
    int t=0;
    cin>>t;                     
    for(int i=0;i<t;i++)
    {
        int n=0;
        cin>>n;
        wood *mt=new wood[n];
        bool *book=new bool[n]; 
        for(int j=0;j<n;j++)
        {
            cin>>mt[j].len>>mt[j].wid;
            book[j]=0;
        }
        sort(mt,mt+n,cmp2);            
        int cur_l=0,cur_w=0,coun=0;
        for(int k=0;k<n;k++)
        {
            if(book[k]==0)
            {
                cur_l=mt[k].len;
                cur_w=mt[k].wid;
                book[k]=1;
                coun++;
                for(int j=k+1;j<n;j++)
                {
                    if(book[j]==0 && mt[j].len>=cur_l && mt[j].wid>=cur_w)
                    {
                        cur_l=mt[j].len;
                        cur_w=mt[j].wid;
                        book[j]=1;
                    }
                }
            }
        }
        cout<<coun<<endl;
    }
    return 0;
}
//棋差一着，没想到要用一个是否访问的标记，导致无法取出最长上升子序列
// #include <bits/stdc++.h>
// using namespace std;
// struct node{
//     int l,w;
// };
// bool comp(const node&x,const node&y){
//     return x.l<y.l;
// }
// bool comp1(const node&x,const node&y){
//     return x.w<y.w;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<node> cont(n);
//         for(int i=0;i<n;i++)cin>>cont[i].l>>cont[i].w;
//         sort(cont.begin(),cont.end(),comp);
//         vector<int> dp;
//         dp.assign(n,1);
//         for(int i=1;i<n;i++)
//         for(int j=0;j<i;j++)if(cont[j].w<=cont[i].w)dp[i]=max(dp[i],dp[j]+1);
//         int ans=*max_element(dp.begin(),dp.end());
//         cout<<1+(n-ans)<<"\n";
//     }
//     return 0;
// }