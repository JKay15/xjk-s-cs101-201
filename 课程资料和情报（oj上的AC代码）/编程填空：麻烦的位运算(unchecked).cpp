#include <iostream>
using namespace std;

int bitManipulation4(int n) {
  return
// 在此处补充你的代码
(n&1)?(1|((bitManipulation4(unsigned(n)>>1))<<1)):0
;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << bitManipulation4(n) << endl;
    }
    return 0;
}