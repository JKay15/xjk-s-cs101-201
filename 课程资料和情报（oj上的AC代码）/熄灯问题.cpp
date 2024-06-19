#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
int light[10][10];
int press[10][10];
bool guess()
{
    for (int r = 1; r < 5; r++)
    {
        for (int c = 1; c < 7; c++)
        {
            press[r + 1][c] = (light[r][c] + press[r][c] + press[r][c - 1] + press[r][c + 1] + press[r - 1][c]) % 2;
        }
    }
    for (int c = 1; c < 7; c++)
    {
        if ((press[5][c - 1] + press[5][c + 1] + press[5][c] + press[4][c]) % 2 != light[5][c])
        {
            return false;
        }
    }
    return true;
}
void enumerate()
{
    for (int i = 1; i < 7; i++)
    {
        press[1][i] = 0;
    }
    while (guess() == false)
    {
        press[1][1]++;
        int c = 1;
        while (press[1][c] > 1)
        {
            press[1][c] = 0;
            press[1][c + 1]++;
            c++;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> light[i][j];
        }
    }
    enumerate();
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cout << press[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}