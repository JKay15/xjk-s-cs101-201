#include <bits/stdc++.h>
using namespace std;
char Left[3][7];
char Right[3][7];
char res[3][7];
bool check(char x, bool light)
{
    for (int i = 0; i < 3; i++)
    {
        char *pLeft, *pRight;
        if (light)
        {
            pLeft = Left[i];
            pRight = Right[i];
        }
        else
        {
            pLeft = Right[i];
            pRight = Left[i];
        }
        if (res[i][0] == 'u')
        {
            if (strchr(pRight, x) == NULL)
                return false;
        }
        else if (res[i][0] == 'd')
        {
            if (strchr(pLeft, x) == NULL)
                return false;
        }
        else
        {
            if (strchr(pLeft, x) || strchr(pRight, x))
                return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            cin >> Left[i] >> Right[i] >> res[i];
        for (char c = 'A'; c < 'M'; c++)
        {
            if (check(c, true))
            {
                cout << c << " is the counterfeit coin and it is light.\n";
                break;
            }
            if (check(c, false))
            {
                cout << c << " is the counterfeit coin and it is heavy.\n";
                break;
            }
        }
    }
    return 0;
}