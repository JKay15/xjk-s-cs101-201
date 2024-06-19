#include <stdio.h>
int n,m,f[25][25] = {0};
int main()
{
    scanf("%d%d", &n, &m); 
    f[0][1] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)f[i][j] = f[i - 1][j] + f[i][j - 1]; 
    printf("%d", f[n][m]); 
    return 0;
}