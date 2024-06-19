//动态规划好像对于某些边界条件的讨论有问题
//我们对dp数组的含义也搞错了，明明是bool。非得存下来w1，w1明明是第二个坐标
//其他没啥，很明显的背包
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
const int maxn1 = 110;
const int maxn2 = 45100;
bool dp[maxn1][maxn2];
int num[maxn1];
int sum;
int main()
{
    int n;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        sum = 0;
        for(int i=0; i<n; i++)
        {
            cin>>num[i];
            sum += num[i];
        }
        int sum1,n1;
        sum1 = sum / 2;
        n1 = n / 2;
        if(n % 2)
            n1 += 1;
        if(sum % 2)
            sum1 += 1;
        dp[0][0] = true;

        for(int i=0; i<n; i++)
            for(int j=n1; j>=1; j--)
                for(int k=sum1; k>=num[i]; k--)
                {
                    if(dp[j-1][k-num[i]])
                        dp[j][k] = true;
                }

        int Max = 0;
        for(int i=sum1; i>=0; i--)
        {
            if(dp[n1][i])
            {
                Max = i;
                break;
            }
        }
        if(Max == 0)
        {
            for(int i=sum1; i>=0; i--)
            {
                if(dp[n1-1][i])
                {
                    Max = i;
                    break;
                }
            }
        }

        cout<<min(Max,sum-Max)<<" "<<max(Max,sum-Max)<<endl;
    }
    return 0;
}