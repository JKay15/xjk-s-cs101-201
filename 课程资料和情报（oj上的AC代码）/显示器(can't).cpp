//对于一个数字7个部分的拆分，我实在是没想到
//对于这种人的理解应该是从上至下，但是输出只能按行输出的，的确是没有处理的经验
//这个7部分规律找到了之后，应该是很好做的

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;
int s;
char ss[7][11] = {
    {"- -- -----"},
    {"|   ||| ||"},
    {"|||||  |||"},
    {"  ----- --"},
    {"| |   | | "},
    {"|| |||||||"},
    {"- -- -- --"}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string tmp;
    while (cin >> s >> tmp && s)
    {
        int l = tmp.length();
        for (int i = 0; i < l; i++)
        {
            int digit = tmp[i] - '0';
            cout << ((i == 0) ? " " : "  ");
            for (int j = 0; j < s; j++)
            {
                cout << ss[0][digit];
            }
            cout << " ";
        }
        cout << endl;
        for (int i = 0; i < s; i++)
        {
            for (auto j : tmp)
            {
                int digit = j - '0';
                cout << ss[1][digit];
                for (int k = 0; k < s; k++)
                {
                    cout << " ";
                }
                cout << ss[2][digit];
                cout<<" ";
            }
            cout << endl;
        }
        for (auto i : tmp)
        {
            int digit = i - '0';
            cout << " ";
            for (int j = 0; j < s; j++)
            {
                cout << ss[3][digit];
            }
            cout << "  ";
        }
        cout << endl;
        for (int i = 0; i < s; i++)
        {
            for (auto j : tmp)
            {
                int digit = j - '0';
                cout << ss[4][digit];
                for (int k = 0; k < s; k++)
                {
                    cout << " ";
                }
                cout << ss[5][digit];
                cout<<" ";
            }
            cout << endl;
        }
        for (auto i : tmp)
        {
            int digit = i - '0';
            cout << " ";
            for (int j = 0; j < s; j++)
            {
                cout << ss[6][digit];
            }
            cout << "  ";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}