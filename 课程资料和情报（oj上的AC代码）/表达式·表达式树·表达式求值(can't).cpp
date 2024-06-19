#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
string str;
int n;
int res;
vector<int> oprand;
vector<char> oprator;
vector<char> cont;
unordered_map<char, int> variable;
vector<char> suf;
bool check(char x, char y)
{
    if (x == '(')
        return 1;
    else if (x == ')' && y == '(')
    {
        return -1;
    }
    else if (((x == '+') || (x == '-')) && ((y == '+') || (y == '-')))
    {
        return 0;
    }
    else if (((x == '*') || (x == '/')) && ((y == '*') || (y == '/')))
    {
        return 0;
    }
    else if (((x == '*') || (x == '/')) && ((y == '+') || (y == '-')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void suffix()
{
    for (char i : str)
    {
        if (i>='a'&&i<='z')
        {
            oprand.push_back(variable[i]);
            suf.push_back(i);
        }
        else
        {
            if (oprator.empty())
            {
                oprator.push_back(i);
            }
            else
            {
                while (oprator.size() > 0)
                {
                    int tag = check(i, oprator.back());
                    if (tag == 1)
                    {
                        oprator.push_back(i);
                        break;
                    }
                    else if (tag == 0)
                    {
                        cont.push_back(oprator.back());
                        suf.push_back(oprator.back());
                        oprator.pop_back();
                    }
                    else
                    {
                        oprator.pop_back();
                        break;
                    }
                }
            }
        }
    }
    for (char i : suf)
    {
        cout << i;
    }
    while (oprator.size() > 0)
    {
        cont.push_back(oprator.back());
        oprator.pop_back();
    }
    for (char i : cont)
    {
        cout << i;
        int tmp1 = oprand.back();
        oprand.pop_back();
        int tmp2 = oprand.back();
        oprand.pop_back();
        if (i == '+')
        {
            oprand.push_back(tmp1 + tmp2);
        }
        else if (i == '-')
        {
            oprand.push_back(tmp1 - tmp2);
        }
        else if (i == '*')
        {
            oprand.push_back(tmp1 * tmp2);
        }
        else
        {
            oprand.push_back(tmp1 / tmp2);
        }
    }
    res = oprand.back();
}
vector<char> op;
vector<char> var;
struct node{
    char x;
    node* left=nullptr;
    node* right=nullptr;
}*root;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str >> n;
    for (int i = 0; i < n; i++)
    {
        char tmp;
        int tmp1;
        cin >> tmp >> tmp1;
        variable.insert({tmp, tmp1});
    }
    suffix();
    cout << endl
         << res << endl;
    tree();
    return 0;
}