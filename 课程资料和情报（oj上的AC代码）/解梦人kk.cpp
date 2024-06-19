#include <bits/stdc++.h>
using namespace std;
string spiralTranslate(int n, vector<vector<int>>& grid) {
    string result = "";
    int direction = 0; 
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; ++i) {
                result += to_string(grid[top][i]);
            }
            ++top;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; ++i) {
                result += to_string(grid[i][right]);
            }
            --right;
        } else if (direction == 2) {
            for (int i = right; i >= left; --i) {
                result += to_string(grid[bottom][i]);
            }
            --bottom;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; --i) {
                result += to_string(grid[i][left]);
            }
            ++left;
        }
        direction = (direction + 1) % 4;
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    string result = spiralTranslate(n, grid);
    cout << result << endl;
    return 0;
}
