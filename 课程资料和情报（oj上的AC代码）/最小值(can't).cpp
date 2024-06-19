//就是裸的线段树
//之前过不了的唯一原因就是query用了区间覆盖的办法，导致需要递归更多的层数，如果用区间收缩就完全没有这个问题，因为区间收缩不一定要到叶子结点，只要左右匹配就返回
//至于说是否吧mmax和mmin放全局，不是很重要，inline也无所谓，位运算会快一丢丢，但也不影响大局
//优化的版本，不要用结构体，用一维数组就可以维护一个线段树，只需要在功能函数中加入区间左右端点的信息就好
//目前没做到的是怎么在a变多的情况下build
//以及完全不用存a，在build的叶子结点输入就好了，很妙
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100861111
#define lc (k<<1)
#define rc ((k<<1)|1)
int k,q,x,y,z,tree[((1<<17)+1)<<2][2],num;
ll mmax,mmin;
inline void pushup(int k)
{
    tree[k][1]=min(tree[lc][1],tree[rc][1]);
    tree[k][0]=max(tree[lc][0],tree[rc][0]);
}
inline void build(int k,int l,int r){
    if(l==r){
        scanf("%d",&tree[k][1]);
        tree[k][0]=tree[k][1];
        return;
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(k);
}
inline void update(int k,int l,int r,int i,int v){
    if(l==r&&l==i){tree[k][0]=tree[k][1]=v;return;}
    int mid=(l+r)>>1;
    if(i<=mid)update(lc,l,mid,i,v);
    else update(rc,mid+1,r,i,v);
    pushup(k);
}
void query(int k,int l0,int r0,int l,int r){
    if(l0==l&&r0==r){
        if(tree[k][0]>mmax)mmax=tree[k][0];
        if(tree[k][1]<mmin)mmin=tree[k][1];
        return;
    }
    int mid=(l0+r0)>>1;
    if(r<=mid)query(lc,l0,mid,l,r);
    else if(l>mid)query(rc,mid+1,r0,l,r);
    else{
        query(lc,l0,mid,l,mid);
        query(rc,mid+1,r0,mid+1,r);
    }
}
int main(){
    scanf("%d",&k);
    num=(1<<k)-1;
    build(1,0,num);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            mmax=-INF,mmin=INF;
            query(1,0,num,y,z);
            if(mmin>=0)printf("%lld\n",mmin*mmin);
            else if(mmax>=0)printf("%lld\n",mmax*mmin);
            else printf("%lld\n",mmax*mmax);
        }else update(1,0,num,y,z);
    }
    return 0;
}