#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

const double q = (1 + sqrt(5.0)) / 2.0;

bool isWythoff(int a, int b)
{

    int t;
    if (a > b)
        t = a, a = b, b = t;
    return (int)((b - a) * q) == a;
}
int x, y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> x >> y)
    {
        cout << !(isWythoff(x, y)) << endl;
    }
    return 0;
}