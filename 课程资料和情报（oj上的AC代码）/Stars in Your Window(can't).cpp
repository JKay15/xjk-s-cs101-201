#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn=10005;
struct info{
	ll maxv;
};
struct tag{
	ll add;
};
info operator+(const info&x,const info& y){
	return {max(x.maxv,y.maxv)};
}
info operator+(const info&x,const tag&y){
	return {x.maxv+y.add};
}
tag operator+(const tag&x,const tag& y){
	return {x.add+y.add};
}
struct node{
	tag t;
	info val;
}seg[maxn<<2];
void update(int id){
	seg[id].val=seg[id<<1].val+seg[id<<1|1].val;
}
void settag(int id,tag t){
	seg[id].val=seg[id].val+t;
	seg[id].t=seg[id].t+t;
}
void pushdown(int id){
	if(seg[id].t.add!=0){
		settag(id<<1,seg[id].t);
		settag(id<<1|1,seg[id].t); 
		seg[id].t.add=0;
	}
}
void build(int id,int l,int r){
	if(l==r)seg[id].val={0};
	else{
		int mid =(l+r)>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		update(id);
	}
}
void modify(int id,int l,int r,int ql,int qr,tag t){
	if(l==ql&&r==qr){
		settag(id,t);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(id);
	if(ql<=mid)modify(id<<1,l,mid,ql,qr,t);
	else if(qr>mid)modify(id<<1|1,mid+1,r,ql,qr,t);
	else{
		modify(id<<1,l,mid,ql,qr,t); 
		modify(id<<1|1,mid+1,r,ql,qr,t);
	}
	update(id);
}
info query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr)return seg[id].val;
	int mid=(l+r)>>1;
	pushdown(id);
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	else if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return query(id<<1,l,mid,ql,qr)+query(id<<1|1,mid+1,r,ql,qr);
}