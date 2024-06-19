// 没有大小规律就模拟，当然这里做出了对2x+1和3x+1的区分，这是很巧妙的
#include <bits/stdc++.h>
using namespace std;
long long a, n;
queue<int> q1;
queue<int> q2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> a >> n)
    {
        n--;
        q1={};
        q2={};
        while (n--)
        {
            q1.push(2 * a + 1);
            q2.push(3 * a + 1);
            if (q1.front() < q2.front())
            {
                a = q1.front();
                q1.pop();
            }
            else if (q1.front() > q2.front())
            {
                a = q2.front();
                q2.pop();
            }
            else
            {
                a = q1.front();
                q1.pop();
                q2.pop();
            }
        }
        printf("%lld\n", a);
    }
    return 0;
}