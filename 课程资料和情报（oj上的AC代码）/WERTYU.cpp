//神奇。不知道为什么过不了
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, char> lis{{'1', '`'}};
string line[4] = {"0-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp;
    for (string x : line)
    {
        int l = x.length();
        for (int i = l - 1; i > 0; i--)
            lis.insert({x[i], x[i - 1]});
    }
    while (getline(cin, tmp))
    {
        for (char x : tmp)
        {
            if (x == ' ')
                cout<< x;
            if (x >= '2' && x <= '9')
                cout<< char(x - 1);
            else if (x == '0')
                cout<< '9';
            else if(x=='A'||x=='Q'||x=='Z'||x=='`')
                continue;
            else
                cout<< lis[x];
        }
        cout<<endl;
    }
    return 0;
}