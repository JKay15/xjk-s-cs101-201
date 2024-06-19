#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 5;
const int INF = 0x3f3f3f3f;
int c[MAX];
int n,L,A,B;
deque<int> dq;
int dp[MAX];
int main()
{
	cin>>n>>L;
	cin>>A>>B;
	A*=2,B*=2; 
	for(int s,e,i = 1; i<=n; i++) {
		scanf("%d%d",&s,&e);
		s++,e--;
		c[s]++;c[e+1]--;
	}
	dp[0]=0;
	for(int i = 1; i<=L; i++) {
		c[i] += c[i-1];
		if(i & 1) continue;
		while(dq.size() && dq.front() < i - B) dq.pop_front();
		if(i-A>=0) {
			while(dq.size() && dp[dq.back()] > dp[i-A]) dq.pop_back();
			dq.push_back(i-A); 
		} 
		if(dq.size() && dp[dq.front()] < INF && c[i] == 0) dp[i] = dp[dq.front()]+1;
		else dp[i] = INF;
	}
	if(dp[L] == INF) printf("-1");
	else printf("%d",dp[L]);
	return 0 ;
}