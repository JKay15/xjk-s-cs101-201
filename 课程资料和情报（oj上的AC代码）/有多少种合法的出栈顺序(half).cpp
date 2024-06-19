//要写高精度，所以我懒得写了
#include <cstdio>
long long n,f[1005];
int main()
{
    scanf("%lld", &n);
    f[0] = 1, f[1] = 1;
    for(int i=2; i<=n; i++)              
    for(int j=0; j<i; j++)f[i] += f[j] * f[i-j-1];    
    printf("%lld", f[n]);
    return 0;
}