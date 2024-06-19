#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> cont;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        cont.push_back(tmp);
    }
    while (m)
    {
        if (!std::next_permutation(cont.begin(), cont.end()))
        {
            int i = 1;
            for_each(cont.begin(), cont.end(), [&i](int &x)
                     { x = i++; });
        }
        m--;
    }
    for_each(cont.begin(), cont.end(), [](int x)
             { cout << x << " "; });
    cout << endl;

    return 0;
}
