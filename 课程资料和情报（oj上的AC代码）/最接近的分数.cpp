//很明显，这里的理解还是有点不足
//如果想到了能够单纯大小就行就好了，对于特征的提取不是很好
//比如对于分子分母大小的变化没有多了解，甚至用了double


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// using namespace std;
// #define INF 0x7777777
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int a, b, n;
//     cin >> n >> a >> b;
//     int parent = n;
//     double tar = 1.0 * a / b;
//     double mmin = INF;
//     int ans1 = 0;
//     int ans2 = 0;
//     while (parent > 1)
//     {
//         for (int i = parent - 1; i >= 1; i--)
//         {
//             if (parent % i == 0 || double(1.0 * i / parent) >= tar)
//             {
//                 continue;
//             }
//             else
//             {
//                 if (tar - 1.0 * i / parent < mmin)
//                 {
//                     mmin = tar - 1.0 * i / parent;
//                     ans1 = i;
//                     ans2 = parent;
//                 }
//             }
//         }
//         parent--;
//     }
//     cout << ans1 << " " << ans2 << endl;

//     return 0;
// }

#include <iostream>

using namespace std;

int main()
{
    int n, a, b, p, q, x, y;

    scanf("%d%d%d", &n, &a, &b);

    // 分子x从1-n，分母y从n-1；结果p/q，开始时1/n（最小值）
    p = 1, q = n;
    for(x=1; x<=n; x++)
        for(y=n; y>=1; y--)
            if(b * x < a * y && x * q > p * y)
                p = x, q = y;

    printf("%d %d\n", p, q);

    return 0;
}
