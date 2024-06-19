//等量替换的思想，就是小学奥数和脑经急转弯
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases, l, n, min, max, temp_min, temp_max, pos;
    cin >> cases;
    while (cases--)
    {
        cin >> l >> n;
        min = 0;
        max = 0;
        while (n--)
        {
            cin >> pos;
            temp_min = pos > l - pos ? l - pos : pos;
            temp_max = pos < l - pos ? l - pos : pos;
            if (temp_min > min)
                min = temp_min;
            if (temp_max > max)
                max = temp_max;
        }
        cout << min << ' ' << max << endl;
    }

    return 0;
}