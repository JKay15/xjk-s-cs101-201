//括号匹配
#include <bits/stdc++.h>
const int maxn=50000;
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
int tape[maxn] = {0};
int used[maxn] = {0};
int stack[maxn] = {0}, len = 0, maxlen = 0;
int lastPos[maxn] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tape[i]);
        lastPos[tape[i]] = i;
    }
    int fail = 0;
    for (int i = 0; i <= n; i++)
    {
        if (tape[i] == 0)
        {
            if (len != 0)
            {
                fail = 1;
                break;
            }
            else continue;
        }
        if (!used[tape[i]])
        {
            used[tape[i]] = 1;
            stack[len++] = tape[i];
            maxlen = MAX(maxlen, len);
        }
        if (tape[i] == stack[len - 1])
        {
            if (i == lastPos[tape[i]])len--;
        }
        else
        {
            fail = 1;
            break;
        }
    }
    std::cout<<((fail)?-1:maxlen);
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// struct node{
//     int s,e;
// }a[50001];
// int n,ans,l,where=1,pos[50001];
// vector<int> ran;
// int dfs(int x,int up){
//     int res=1,i=x+1;
//     for(;i<l&&a[ran[i]].e<up;i++){
//         if(a[ran[i]].e<a[ran[x]].e){
//             res=max(res,1+dfs(i,a[ran[x]].e));
//             i=where-1;
//         }else x=i;
//     }
//     where=i;
//     return res;
// }
// int main(){
//     cin>>n;
//     ran.push_back(0);
//     for(int i=1;!ans&&i<=n;i++){
//         cin>>l;
//         if(!pos[l]){
//             a[l].s=a[l].e=i;
//             ran.push_back(l);
//             pos[l]=ran.size()-1;
//         }else{
//             a[l].e=i;
//             if(pos[0]&&a[0].s>a[l].s)ans=1;
//             for(int j=1;!ans&&j<pos[l];j++)if(a[ran[j]].e>a[l].s)ans=1;
//         }
//     }
//     l=ran.size();
//     cout<<((ans)?-1:dfs(1,50001));
//     return 0;
// }
//写炸了的线段树
// #include <bits/stdc++.h>
// using namespace std;
// #define lc (k<<1)
// #define rc ((k<<1)+1)
// const int maxn=5;
// struct node{
//     int s,e;
// }a[maxn];
// struct tree1{
//     int l,r,_max;
// }tree[maxn<<2];
// int n,ans,l,where=1,pos[maxn];
// vector<int> ran;
// int dfs(int x,int up){
//     int res=1,i=x+1;
//     for(;i<l&&a[ran[i]].e<up;i++){
//         if(a[ran[i]].e<a[ran[x]].e){
//             res=max(res,1+dfs(i,a[ran[x]].e));
//             i=where-1;
//         }else x=i;
//     }
//     where=i;
//     return res;
// }
// void build(int k,int l,int r){
//     if(l==r){
//         tree[k].l=tree[k].r=l;
//         tree[k]._max=a[ran[l]].e;
//         return ;
//     }
//     int mid=(l+r)/2;
//     build(lc,l,mid);
//     build(rc,mid+1,r);
//     tree[k].l=l;tree[k].r=r;
//     tree[k]._max=max(tree[lc]._max,tree[rc]._max);
// }
// void update(int k,int i,int v){
//     if(tree[k].l==tree[k].r&&tree[k].l==i){tree[k]._max=v;return;}
//     int mid=(tree[k].l+tree[k].r)/2;
//     if(mid>=i)update(lc,i,v);
//     else update(rc,i,v);
//     tree[k]._max=max(tree[lc]._max,tree[rc]._max);
// }
// int query(int k,int l,int r){
//     if(l==r)return tree[k]._max;
//     int mid=(tree[k].l+tree[k].r)/2,res=-0x7777777;
//     if(mid>=l)res=max(res,query(lc,l,r));
//     if(mid<r)res=max(res,query(rc,l,r));
//     return res;
// }
// int main(){
//     cin>>n;
//     ran.push_back(0);
//     for(int i=1;!ans&&i<=n;i++){
//         cin>>l;
//         if(!pos[l]){
//             a[l].s=a[l].e=i;
//             ran.push_back(l);
//             pos[l]=ran.size()-1;
//             if(i==1)build(1,1,1);
//             else update(1,pos[l],i);
//         }else{
//             a[l].e=i;
//             update(1,pos[l],i);
//             if((pos[0]&&a[0].s>a[l].s)||(pos[l]>1&&query(1,1,pos[l]-1)>a[l].s))ans=1;
//         }
//     }
//     cout<<((ans)?-1:dfs(1,maxn));
//     return 0;
// }