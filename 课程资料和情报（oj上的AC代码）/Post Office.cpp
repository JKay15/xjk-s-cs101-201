#include <bits/stdc++.h>
using namespace std;
inline int gi()
{
	int f = 1, x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return f * x;
}
int n,m,a[305],b[305][305],dp[305][305];
int main()
{
	n = gi(), m = gi();
	for (int i = 1; i <= n; i++)a[i] = gi();
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i < n; i++)
	for (int j = i + 1; j <= n; j++)b[i][j] = b[i][j - 1] + a[j] - a[(i + j) >> 1];
	for (int i = 1; i <= n; i++)dp[i][1] = b[1][i];
	for (int i = 2; i <= m; i++)
	for (int j = i; j <= n; j++)
	for(int k = i - 1; k <= j - 1; k++)dp[j][i] = min(dp[j][i], dp[k][i - 1] + b[k + 1][j]);
	printf("%d",dp[n][m]);
	return 0;
}