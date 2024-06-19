//y方向没有真正的排序，所以不应该y出界了就不再尝试这个i下的其他j
//能想到枚举两个起点就成功了一半
//之后的剪枝就要看自己的细心和经验了
//第一个是要看是否枚举的第一个点真的没有前置点了，有的话要扩大步长，枚举更大的j
//之后要看是否第三个点就出界了，分两个讨论，x出界，因为x严格上升排序，所以没必要继续枚举j
//y出界，因为y不是严格上升，所以只是这个j不行，继续枚举更大的j
//另外为啥i不需要枚举n-2，不清楚。。。
#include <bits/stdc++.h>
using namespace std;
int r, c, n;
struct point
{
    int x, y;
};
point plants[5001];
int searchPath(point secPlant, int dX, int dY)
{
    point plant;
    int steps = 2;
    plant.x = secPlant.x + dX;
    plant.y = secPlant.y + dY;
    while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1)
    {
        if (!binary_search(plants, plants + n, plant))
        {
            steps = 0;
            break;
        }
        plant.x += dX;
        plant.y += dY;
        steps++;
    }
    return (steps);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int dX, dY, pX, pY, steps, mmax = 2;
    cin >> r >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> plants[i].x >> plants[i].y;
    sort(plants, plants + n);
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
        {
            dX = plants[j].x - plants[i].x;
            dY = plants[j].y - plants[i].y;
            pX = plants[i].x - dX;
            pY = plants[i].y - dY;
            if (pX <= r && pX >= 1 && pY <= c && pY >= 1)
                continue;
            if (plants[i].x + (mmax - 1) * dX > r)
                break;
            pY = plants[i].y + (mmax - 1) * dY;
            if (pY > c || pY < 1)
                continue;
            steps = searchPath(plants[j], dX, dY);
            mmax = ((steps > mmax) ? steps : mmax);
        }
    mmax = ((mmax == 2) ? 0 : mmax);
    cout << mmax << endl;
    return 0;
}
bool operator<(const point &p1, const point &p2)
{
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}