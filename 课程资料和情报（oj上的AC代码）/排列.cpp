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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> cont;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            cont.push_back(tmp);
        }
        while (k)
        {
            if (std::next_permutation(cont.begin(), cont.end()))
            {
                k--;
                continue;
            }
            else
            {
                int i = 1;
                for_each(cont.begin(), cont.end(), [&i](int &x)
                         { x = i++; });
                k--;
            }
        }
        for_each(cont.begin(), cont.end(), [](int x)
                 { cout << x << " "; });
        cout << endl;
    }

    return 0;
}