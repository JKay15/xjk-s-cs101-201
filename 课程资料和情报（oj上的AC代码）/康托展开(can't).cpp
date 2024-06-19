//树状数组，使用前缀和的方式，算出某个数字之后有几个比他小的
//实际上就是一个原本都是1的树状数组，如果要算后面比他小的，实际上就是还没有出现过且比它小的，因此出现过的位置变成0就好了，这样就转化为了区间和的形式

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n;
ll jc[1000005]={1,1},tree[1000005];
const ll wyx=998244353;
int lowbit(int x){
	return x&-x;
}
void update(int x,int y){
	while(x<=n){
		tree[x]+=y;
		x+=lowbit(x);	
	}
}
ll query(int x){
	ll sum=0;
	while(x){
		sum+=tree[x];
		x-=lowbit(x);	
	}
	return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){
		jc[i]=(jc[i-1]*i)%wyx;
		update(i,1);
	}
    ll ans=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=(ans+((query(a[i])-1)*jc[n-i])%wyx)%wyx;
		update(a[i],-1);
	}
    cout<<ans+1<<"\n";
    return 0;
}