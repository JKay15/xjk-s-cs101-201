#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
const int maxn = 1005;
int r, n;
int pos[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> r >> n && r != -1)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> pos[i];
        }
        sort(pos + 1, pos + n + 1);
        int total = 0;
        int left = 1;
        int right = 0;
        while (right < n)
        {
            if (left == 1)
            {
                left++;
            }
            else
            {
                if (pos[right + 1] + r >= pos[left])
                {
                    left++;
                }
                else
                {
                    total++;
                    right = left - 1;
                    while (pos[right] - r <= pos[left - 1] && right <= n)
                    {
                        right++;
                    }
                    right--;
                }
            }
        }
        cout << total << endl;
    }

    return 0;
}