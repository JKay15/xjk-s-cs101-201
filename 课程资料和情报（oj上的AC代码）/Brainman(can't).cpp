#include <bits/stdc++.h>
using namespace std;
int t,a[1005],n,ans;
//这题的样例我真的不知道是咋来的——看错题了，把n当作a的第一个元素了
void merging(int l,int m,int r){
    vector<int> cont;
    int cl=l,cr=m+1,ans=0;
    while(cl<=m&&cr<=r){
        if(a[cl]<=a[cr])cont.push_back(a[cl++]);
        else{
            ans+=m-cl+1;
            cont.push_back(a[cr++]);
        }
    }
    while(cl<=m)cont.push_back(a[cl++]);
    while(cr<=r)cont.push_back(a[cr++]);
    for(int i=l,j=0;i<=r;i++,j++)a[i]=cont[j];
}
void sorting1(int l,int r){
    if(l>=r)return ;
    int m=(l+r)>>1;
    sorting1(l,m),sorting1(m+1,r),merging(l,m,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        printf("Scenario #%d:\n",i);
        scanf("%d",&n);
        for(int j=0;j<n;j++)scanf("%d",&a[j]);
        ans=0;
        sorting1(0,n-1);
        printf("%d\n\n",ans);
    }
    return 0;
}
// #include <iostream>
// #include <stdio.h>
// using namespace std;
// const int N = 20;
// int a[N], b[N];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int k = 1; k <= n; k++)
//     {
//         int m;
//         scanf("%d", &m);
//         for (int i = 1; i <= m; i++)
//             scanf("%d", &a[i]);
//         int ans = 0;
//         for (int i = 1; i <= m; i++)
//             for (int j = i + 1; j <= m; j++)
//                 if (a[i] > a[j])
//                     ans++;
//         printf("Scenario #%d:\n%d\n\n", k, ans);
//     }
//     return 0;
// }