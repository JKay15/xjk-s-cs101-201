//对于STL库函数的熟练运用，可以打打节省代码量
//首先把四个数的和分为两部分
//其中一部分好好算出加和的可能性后排序
//另一部分就可以在枚举所有加和可能性的同时，二分在之前加和结果中寻找为其相反数的个数——用upper_bound-lower_bound就可以
//有空得再研究一下upper_bound和lower_bound
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> A(n + 5);
    vector<int> B(n + 5);
    vector<int> C(n + 5);
    vector<int> D(n + 5);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    int ssum[n * n + 5];
    int total = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        ssum[n * i + j] = C[i] + D[j];
    sort(ssum, ssum + n * n);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
        int tag = -(A[i]+B[j]);
        total+=upper_bound(ssum,ssum+n*n,tag)-lower_bound(ssum,ssum+n*n,tag);
    }
    cout << total << endl;
    return 0;
}