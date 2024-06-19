#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 105;
string DNA[maxn];
struct lis {
    string x;
    int y;
    lis() {}
    lis(string &str, int num) : x(str), y(num) {}
};

lis Rev[maxn];

lis merge(string x, string y) {
    string tmp = "";
    int cnt = 0;
    int i = 0;
    int j = 0;
    while (i < x.length() && j < y.length()) {
        if (x[i] <= y[j]) {
            tmp += x[i];
            i++;
        } else {
            tmp += y[j];
            j++;
            cnt += x.length() - i;
        }
    }
    tmp += x.substr(i);
    tmp += y.substr(j);
    return lis(tmp, cnt);
}

lis get_num(string x) {
    if (x.length() <= 1) {
        return lis(x, 0);
    }
    int mid = x.length() / 2; // 修正计算mid的方式
    lis left = get_num(x.substr(0, mid));
    lis right = get_num(x.substr(mid));
    lis res = merge(left.x, right.x);
    return lis(res.x, res.y + left.y + right.y);
}

int cmp(lis x, lis y) {
    return x.y < y.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> DNA[i];
        Rev[i] = lis(DNA[i], get_num(DNA[i]).y);
    }
    sort(Rev, Rev + m, cmp);
    for (int i=0;i<m;i++) {
        cout << Rev[i].x << endl;
    }

    return 0;
}