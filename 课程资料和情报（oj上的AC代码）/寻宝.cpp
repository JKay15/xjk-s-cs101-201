#include <bits/stdc++.h>
using namespace std;
// 定义四个方向的移动
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool is_valid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}
int treasure_hunt(int m, int n, vector<vector<int>>& treasure_map) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    int steps = 0;

    while (!q.empty()) {
        int size = q.size(); // 记录当前层的节点数

        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (treasure_map[x][y] == 1) {
                return steps; // 返回步数
            }

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (is_valid(nx, ny, m, n) && treasure_map[nx][ny] != 2 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        steps++; // 每一层结束后步数加一
    }

    return -1; // 无法到达
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> treasure_map(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> treasure_map[i][j];
        }
    }
    int result = treasure_hunt(m, n, treasure_map);
    if (result == -1) {
        cout << "NO" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
