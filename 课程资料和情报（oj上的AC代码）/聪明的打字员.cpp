#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#define break_p() game_end = true, ans = node1.step
#define push_point() vis[node1.num][node1.line] = true, Q.push(node1)
using namespace std;
struct node
{
    int num;
    int line;
    int step;
} now, node1;
queue<node> Q;
bool vis[1000001][7], game_end;
int cost[8];
int cur_tar;
int cur_num;
int init, target;
int ans;
void swap0_left()
{
    node1 = node{now.num, now.line - 1, now.step + 1};
    if (!vis[node1.num][node1.line])
        push_point();
    node1 = node{now.num, now.line, now.step + 1};
    cur_tar = node1.num / cost[1];
    node1.num = node1.num - cur_tar * cost[1] + cur_num * cost[1] - cur_num * cost[node1.line] + cur_tar * cost[node1.line];
    if (node1.num == target)
        break_p();
    if (!vis[node1.num][node1.line])
        push_point();
}
void swap1_right()
{
    node1 = node{now.num, now.line + 1, now.step + 1};
    if (!vis[node1.num][node1.line])
        push_point();
    node1 = node{now.num, now.line, now.step + 1};
    cur_tar = node1.num % 10;
    node1.num = node1.num - cur_tar + cur_num - cur_num * cost[node1.line] + cur_tar * cost[node1.line];
    if (node1.num == target)
    {
        break_p();
    }
    if (!vis[node1.num][node1.line])
    {
        push_point();
    }
}
void up()
{
    node1 = node{now.num + cost[node1.line], now.line, now.step + 1};
    if (node1.num == target)
        break_p();
    if (!vis[node1.num][node1.line])
        push_point();
}
void down()
{
    node1 = node{now.num - cost[node1.line], now.line, now.step + 1};
    if (node1.num == target)
        break_p();
    if (!vis[node1.num][node1.line])
        push_point();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cost[1] = 100000;
    for (int i = 2; i < 8; i++)
    {
        cost[i] = cost[i - 1] / 10;
    }
    cin >> init >> target;
    if (init == target)
    {
        cout << 0 << endl;
    }
    else
    {
        Q.push(node{init, 1, 0});
        while (!Q.empty())
        {
            if (game_end)
            {
                break;
            }
            now = Q.front();
            Q.pop();
            cur_num = (now.num / cost[now.line]) % 10;
            if (now.line != 1)
            {
                swap0_left();
            }
            if (now.line != 6)
            {
                swap1_right();
            }
            if (cur_num != 9)
            {
                up();
            }
            if (cur_num != 0)
            {
                down();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
