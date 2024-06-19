#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool isMatch(std::string s, std::string p)
    {
        return dp(s, p);
    }

    static bool dp(std::string s, std::string p)
    {
        int sLen = s.length();
        int pLen = p.length();

        std::vector<std::vector<bool>> dp(sLen + 1, std::vector<bool>(pLen + 1, false));
        dp[sLen][pLen] = true;

        int i = pLen - 1;

        while (i >= 0)
        {
            if (p[i] == '*')
            {
                dp[sLen][i] = true;
                i--;
            }
            else
            {
                break;
            }
        }

        while (i >= 0)
        {
            dp[sLen][i] = false;
            i--;
        }

        for (int sL = sLen - 1; sL >= 0; sL--)
        {
            for (int pL = pLen - 1; pL >= 0; pL--)
            {
                if (p[pL] == '?')
                {
                    dp[sL][pL] = dp[sL + 1][pL + 1];
                }
                else if (p[pL] == '*')
                {
                    dp[sL][pL] = dp[sL][pL + 1] || dp[sL + 1][pL + 1] || dp[sL + 1][pL];
                }
                else
                {
                    if (p[pL] == s[sL])
                    {
                        dp[sL][pL] = dp[sL + 1][pL + 1];
                    }
                    else
                    {
                        dp[sL][pL] = false;
                    }
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string s,p;
            cin>>s>>p;
            if(Solution().isMatch(s,p)){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
        return 0;
}
// int n;
// string s, p;
// int dfs(string x, string y)
// {
//     int l1 = x.length();
//     int l2 = y.length();
//     if (y == "*" || x == y)
//         return 1;
//     if (y.find('*') == string::npos && l1 != l2)
//         return 0;
//     int tag1 = 0, tag2 = 0;
//     while (tag1 < l1 && tag2 < l2)
//     {
//         if (y[tag2] == x[tag1] || y[tag2] == '?')
//         {
//             tag1++;
//             tag2++;
//         }
//         else
//         {
//             if (y[tag2] == '*')
//             {
//                 string tmp_y = y.substr(tag2 + 1, l2 - tag2 - 1);
//                 int tag = 0;
//                 int i = tag1;
//                 for (; i <= l1; i++)
//                 {
//                     string tmp_x = x.substr(i, l1 - i);
//                     if (dfs(tmp_x, tmp_y))
//                     {
//                         tag = 1;
//                         return 1;
//                     }
//                 }
//                 if (tag == 0)
//                     return 0;
//             }
//             return 0;
//         }
//     }
//     return ((tag1 == l1 && tag2 == l2) ? 1 : 0);
// }
// void solve()
// {
//     string tmp;
//     cin >> s >> tmp;
//     p = tmp[0];
//     int l = tmp.length();
//     for (int i = 1; i < l; i++)
//     {
//         if (tmp[i] == '*' && tmp[i - 1] == '*')
//         {
//             continue;
//         }
//         else
//         {
//             p += tmp[i];
//         }
//     }
//     cout << ((dfs(s, p)) ? "yes" : "no") << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         solve();
//     }
//     return 0;
// }