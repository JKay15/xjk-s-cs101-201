// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// 	ios::sync_with_stdio(false);cin.tie(nullptr);
// 	int t,n,num,tmp,mid;
// 	cin>>t;
// 	while(t--){
// 		cin>>n;
// 		mid=1<<(n-1);
// 		num=mid<<1;
// 		bool ok[num+5];
// 		for(int i=1;i<=num;i++){
// 			cin>>tmp;
// 			ok[num-tmp+1]=((i<=mid)?0:1);
// 		}
// 		int cur=1,l=0,r=0;
// 		for(int i=1;i<=num&&cur<=n;i++){
// 			(ok[i])?r++:l++;
// 			int x=min(r,l);
// 			while(i>=(1<<cur)&&cur<=n&&x>=((1<<(cur-1))-1)){
// 				cout<<num-i+1<<" ";
// 				cur++;
// 			}
// 		}
// 		cout<<"\n";
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n,a[1<<20];
#define pi pair<int,int>
#define F first
#define S second
#define mp make_pair
int mid,le;
pi calc(int l,int r){
	if(r-l+1<=le){
		int e=0;
		for(int j=l;j<=r;j++)e+=(a[j]>=mid);
		if(e)return mp(e-1,0);return mp(0,1);
	}
	int m=(l+r)>>1;
	pi f=calc(l,m),f_=calc(m+1,r);f.F+=f_.F,f.S+=f_.S;
	if(f.F&&f.S)f.F--,f.S--;
	return f;
}
void sol(){
	scanf("%d",&n);for(int i=0;i<(1<<n);i++)
	scanf("%d",&a[i]);
	for(int t=1;t<=n;t++){
		le=(1<<(n-t));
		int l=1,r=(1<<n),ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(calc(0,(1<<n)-1).S==0)ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d ",ans);
	}
	puts("");
}
int main(){
	int T;scanf("%d",&T);while(T--)sol();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    vector<int> a(1<<k), b(1<<k);
    for (int i = 0; i < (1<<k); i++) {
      cin >> a[i];
      a[i]--;
      b[a[i]] = i;
    }
    
    vector<pair<int, int>> dp(1<<(k+1));
    auto merge = [&] (int i) {
      dp[i].first = dp[i<<1].first + dp[i<<1|1].first;
      dp[i].second = dp[i<<1].second + dp[i<<1|1].second;
      if (dp[i].first && dp[i].second) {
        dp[i].first--;
        dp[i].second--;
      }
    };
 
    auto incr = [&] (int v) {
      if (dp[v].second) dp[v].second--;
      else dp[v].first++;
    };
 
    int cur = 1<<k;
    for (int i = 1; i <= k; i++) {
      fill(dp.begin(), dp.begin()+(1<<i), make_pair(0, 0));
      fill(dp.begin()+(1<<i), dp.begin()+(1<<(i+1)), make_pair(0, 1));
      for (int j = cur; j < (1<<k); j++) {
        int v = b[j]>>(k-i)|1<<i;
        incr(v);
      }
      for (int j = (1<<i)-1; j >= 1; j--) merge(j);
      while (dp[1].second) {
        cur--;
        int v = b[cur]>>(k-i)|1<<i;
        incr(v);
        for (v >>= 1; v; v >>= 1) merge(v);
      }
      cout << cur+1 << " \n"[i==k];
    }
  }
}