//数学上的几何规律没找到，其实这道题没有确定的函数能够直接给出答案，而是需要不断尝试
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double N,C,L;
    while(scanf("%lf%lf%lf",&L,&N,&C)&&N>=0)
    {
        if(N==0||L==0||C==0)
        {
            printf("0.000\n");
            continue;
        }
        double minv = 0,maxv = acos(-1.0), midv;
        double L2 = ( 1 + N * C ) * L;
        while(maxv - minv > 1e-12)    
        {
            midv = (minv + maxv) / 2;
            if( 2 * L2 / L > midv / sin(midv / 2))minv = midv;
            else maxv = midv;
        }
        printf("%.3lf\n",L2 / midv * (1-cos(midv / 2)));
    }
    return 0;
}