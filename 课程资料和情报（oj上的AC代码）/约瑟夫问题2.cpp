// #include <bits/stdc++.h>
// using namespace std;
// const int maxn=200005;
// struct node{
//     int l,r;
//     int val;
// }tree[maxn<<2];
// void build(int id,int l,int r){
//     tree[id].l=l,tree[id].r=r;
//     if(l==r){
//         tree[id].val=1;
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(id<<1,l,mid);
//     build(id<<1|1,mid+1,r);
//     tree[id].val=tree[id<<1].val+tree[id<<1|1].val;
// }
// void change(int p,int id){
//     if(tree[id].l==tree[id].r){
//         //错误的写法——p是数组中的下标而不是线段树中的下标！
//         //tree[p].val=0;
//         tree[id].val=0;
//         return ;
//     }
//     int mid=(tree[id].l+tree[id].r)>>1;
//     if(mid<p)change(p,id<<1|1);
//     else change(p,id<<1);
//     tree[id].val=tree[id<<1].val+tree[id<<1|1].val;
// }
// int query(int x,int id){
//     if(tree[id].l==tree[id].r)return tree[id].l;
//     if(tree[id<<1].val>=x)return query(x,id<<1);
//     return query(x-tree[id<<1].val,id<<1|1);
// }
// int n,k;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>k;
//     build(1,1,n);
//     int pos=1;
//     for(int i=0;i<n;i++){
//         pos=(pos+k-2)%tree[1].val+1;
//         int w=query(pos,1);
//         cout<<w<<" ";
//         change(w,1);
//     }
//     return 0;
// }
//还有树状数组的做法
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=2e5+10;
int n,m,maxx;
int bit[maxn];

inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int pos,int x)
{
	for(int i=pos;i<=maxx;i+=lowbit(i))bit[i]+=x;
}
inline int find_kth(int k)
{
	int ans=0,now=0;
	for(int i=15;i>=0;i--)
	{
		ans+=(1<<i);
		if(ans>maxx||bit[ans]+now>=k)ans-=(1<<i);
		else now+=bit[ans];
	}
	return ans+1;
}

int main()
{
	scanf("%d %d",&n,&m);
	maxx=n;		
	for(int i=1;i<=n;i++)bit[i]=lowbit(i);
	int now=1;
	while(n)
	{
		now=(now-1+m-1)%n+1;
		int ans=find_kth(now);
		add(ans,-1);
		printf("%d ",ans);
		n--;
	}
	return 0;
}
 