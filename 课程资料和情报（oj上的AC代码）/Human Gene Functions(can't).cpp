// 我忘了怎么处理最长公共子序列，所以这题一直在纠结怎么从短的序列增长到长，但是应该从长减小到短，否则找不到递推关系
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 105;

int l1, l2;
int dna1[maxn];
int dna2[maxn];
void change(string &x, int *dna)
{
    int tag = 1;
    for (char i : x)
    {
        if (i == 'A')
        {
            dna[tag++] = 0;
        }
        else if (i == 'C')
        {
            dna[tag++] = 1;
        }
        else if (i == 'G')
        {
            dna[tag++] = 2;
        }
        else
        {
            dna[tag++] = 3;
        }
    }
}
int dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int score[5][5] = {
        {5, -1, -2, -1, -3},
        {-1, 5, -3, -2, -4},
        {-2, -3, 5, -2, -2},
        {-1, -2, -2, 5, -1},
        {-3, -4, -2, -1, 0}};
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> l1;
        string tmp;
        cin >> tmp;
        change(tmp, dna1);
        cin >> l2;
        cin >> tmp;
        change(tmp, dna2);
        dp[1][0] = score[dna1[1]][4];
        dp[0][1] = score[dna2[1]][4];
        for (int i = 1; i <= l1; i++)
        {
            dp[i][0] = dp[i - 1][0] + score[dna1[i]][4];
        }
        for (int i = 1; i <= l2; i++)
        {
            dp[0][i] = dp[0][i - 1] + score[dna2[i]][4];
        }
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (i == 1 && j == 1)
                {
                    dp[1][1] = max(score[dna1[1]][dna2[1]], score[dna1[1]][4] + score[dna2[1]][4]);
                }
                else if (i == 1)
                {
                    if (dna1[1] == dna2[j])
                        dp[1][j] = dp[0][j - 1] + score[dna2[j]][dna1[1]];
                    else
                    {
                        dp[1][j] = max(dp[1][j - 1] + score[dna2[j]][4], dp[0][j - 1] + score[dna2[j]][dna1[1]]);
                    }
                }
                else if (j == 1)
                {
                    if (dna1[1] == dna2[j])
                        dp[i][1] = dp[i - 1][0] + score[dna1[i]][dna2[1]];
                    else
                    {
                        dp[i][1] = max(dp[i - 1][1] + score[dna1[i]][4], dp[i - 1][0] + score[dna1[i]][dna2[1]]);
                    }
                }
                else
                {
                    if (dna1[i] == dna2[j])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + score[dna1[i]][dna2[j]];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j - 1] + score[dna1[i]][dna2[j]], max(dp[i - 1][j] + score[dna1[i]][4], dp[i][j - 1] + score[dna2[j]][4]));
                    }
                }
            }
        }
        cout << dp[l1][l2] << endl;
    }

    return 0;
}