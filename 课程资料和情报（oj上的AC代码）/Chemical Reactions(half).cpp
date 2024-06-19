/*corner case :
(1)一旦确定了要找某个左括号对应的右括号，就不应该处理其中的任何元素了，因为这样会重复处理——递归
(2)因此，碰到左括号后就不能再进入除了右括号之外的分支，但是会有历史遗留问题，因此需要处理之前存下来的now和times——边界
(3)结束遍历，也会有历史遗留问题，要处理,但也会出现不需要处理但是把空字符串放入的情况，要讨论——边界
(4)还有一些掐头去尾数字的问题，这个要小心——预处理
(5)核心思想还是处理括号的递归吧，目前我的方式是专注于找到最外的括号，再去掉这对括号先递归处理里面，不知道有没有更好的办法——递归
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <map>

using namespace std;
string in_str;
map<string, int> std_num;
void pro_mat(string x, vector<string> &mat)
{
    int pre = 0;
    int l = x.length();
    for (int i = 1; i < l; i++)
    {
        if (x[i] == '+' || i == l - 1)
        {
            mat.push_back(x.substr(pre, i - pre + (i == l - 1)));
            pre = i + 1;
        }
    }
}
void pro_ele(map<string, int> &num, string ele, int multi)
{
    int l = ele.length();
    string now = "";
    int times = 1;
    int tag = 0;
    int left = 0;
    int left_pos = -1;
    for (int i = 0; i < l; i++)
    {
        char x = ele[i];
        if (x >= 'A' && x <= 'Z' && tag == 0)
        {
            if (now != "")
            {
                num[now] += times * multi;
                now = "";
                times = 1;
                now += x;
            }
            else
            {
                now += x;
            }
        }
        else if (x >= 'a' && x <= 'z' && tag == 0)
        {
            now += x;
        }
        else if (x == '(')
        {
            if (now != "")
            {
                num[now] += times * multi;
                times = 1;
                now = "";
            }
            left_pos = (tag == 0) ? i : left_pos;
            tag = 1;
            left++;
        }
        else if (x == ')')
        {
            left--;
            if (left == 0)
            {
                int right_pos = i;
                tag = 0;
                i++;
                int tt = 0;
                for (; i < l; i++)
                {
                    if (ele[i] >= '0' && ele[i] <= '9')
                    {
                        tt = tt * 10 + ele[i] - '0';
                    }
                    else
                    {
                        break;
                    }
                }
                if (i != l)
                    i--;
                pro_ele(num, ele.substr(left_pos + 1, right_pos - left_pos - 1), multi * times * ((tt == 0) ? 1 : tt));
            }
        }
        else if (x >= '0' && x <= '9' && tag == 0)
        {
            int tt = ele[i] - '0';
            i++;
            for (; i < l; i++)
            {
                if (ele[i] >= '0' && ele[i] <= '9')
                {
                    tt = tt * 10 + ele[i] - '0';
                }
                else
                {
                    break;
                }
            }
            if (i != l)
                i--;
            times *= tt;
        }
    }
    if (!((ele[l - 1] == '(') || (ele[l - 1] == ')')) && now != "")
    {
        num[now] += times * multi;
    }
}
void process(string x, map<string, int> &cont)
{
    vector<string> mat;
    pro_mat(x, mat);
    for (string ele : mat)
    {
        int pos = 0;
        int times = 0;
        while (ele[pos] >= '0' && ele[pos] <= '9')
        {
            times = times * 10 + (ele[pos++] - '0');
        }
        pro_ele(cont, ele.substr(pos, ele.length() - pos), (times == 0) ? 1 : times);
    }
}
bool check(map<string, int> &cmp)
{
    if (cmp.size() != std_num.size())
    {
        return 0;
    }
    // 遍历 cmp 中的键值对
    for (const auto &pair : cmp)
    {
        const std::string &key = pair.first; // 键
        int cmp_value = pair.second;         // cmp 中的值

        // 查找相同键是否存在于 std_num 中
        auto std_num_iter = std_num.find(key);

        // 如果找到了相同的键，并且值一致，则进行比较
        if (std_num_iter != std_num.end() && std_num_iter->second == cmp_value)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> in_str;
    process(in_str, std_num);
    int t;
    cin >> t;
    while (t--)
    {
        string tmp;
        cin >> tmp;
        map<string, int> cmp;
        process(tmp, cmp);
        if (check(cmp))
        {
            cout << in_str << "==" << tmp << endl;
        }
        else
        {
            cout << in_str << "!=" << tmp << endl;
        }
    }
    return 0;
}