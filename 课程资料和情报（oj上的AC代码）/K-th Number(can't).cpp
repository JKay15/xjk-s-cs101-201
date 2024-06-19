//显然太慢了
// #include <bits/stdc++.h>
// using namespace std;
// int n,m;
// int main(){
//     scanf("%d%d",&n,&m);
//     vector<int> cont(n+1);
//     for(int i=1;i<=n;i++)scanf("%d",&cont[i]);
//     for(int i=0;i<m;i++){
//         int t1,t2,t3;
//         scanf("%d%d%d",&t1,&t2,&t3);
//         vector<int> tmp;
//         for(int j=t1;j<=t2;j++)tmp.push_back(cont[j]);
//         sort(tmp.begin(),tmp.end());
//         printf("%d\n",tmp[t3-1]);
//     }
//     return 0;
// }
//主席树
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],root[maxn],cnt,n,m;
struct node{
    int l,r,sum;
}hjt[maxn*40];
vector<int> v;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int query1(int l,int r,int L,int R,int k){
    if(l==r)return l;
    int m=(l+r)>>1;
    int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;
    if(k<=tmp)return query1(l,m,hjt[L].l,hjt[R].l,k);
    return query1(m+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
void insert1(int l,int r,int pre,int &now,int p){
    now=++cnt;
    hjt[now]=hjt[pre];
    hjt[now].sum++; 
    if(l==r)return ;
    int m=(l+r)>>1;
    if(p<=m)insert1(l,m,hjt[pre].l,hjt[now].l,p);
    else insert1(m+1,r,hjt[pre].r,hjt[now].r,p);
}
inline int getid(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
    n=read();int m=read();
    for(int i=1;i<=n;i++)v.push_back(a[i]=read());
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)insert1(1,n,root[i-1],root[i],getid(a[i]));
    while(m--){
        int l=read(),r=read(),k=read();
        printf("%d\n",v[query1(1,n,root[l-1],root[r],k)-1]);
    }
    return 0;
}