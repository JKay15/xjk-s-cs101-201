#include <bits/stdc++.h>
using namespace std;
int where = 0;
string dfs(int i, string &s, int l)
{
    string tmp = "";
    int cur = 0;
    for (int pos = i; pos < l; pos++)
    {
        if (s[pos] >= '0' && s[pos] <= '9')
        {
            cur = cur * 10 + s[pos] - '0';
        }
        else
        {
            if (s[pos] == '[')
            {
                string tmp1 = dfs(pos + 1, s, l);
                string tmp2=tmp1;
                for (int j = 1; j < cur; j++)
                    tmp1 += tmp2;
                cur=0;
                tmp += tmp1;
                pos = where;
            }
            else if (s[pos] == ']')
            {
                where = pos;
                return tmp;
            }
            else
            {
                tmp += s[pos];
            }
        }
    }
    return tmp;
}
string decodeString(string s)
{
    return dfs(0, s, s.length());
}
int main(){
    string s;
    cin>>s;
    cout<<decodeString(s)<<endl;
}