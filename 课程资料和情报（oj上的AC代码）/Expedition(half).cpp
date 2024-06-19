//思路对了，但是对于单调队列的数据结构不熟，所以用的时候出了RE的错误
#include <bits/stdc++.h>

#define maxn 10010

struct Node {
    int pos, val;
} A[maxn];

bool cmp(Node a, Node b) {
    return a.pos > b.pos;
}

int main() {
    int N, L, P, i, cnt;
    while(scanf("%d", &N) == 1) {
        for(i = 0; i < N; ++i)
            scanf("%d%d", &A[i].pos, &A[i].val);
        scanf("%d%d", &L, &P);
        std::sort(A, A + N, cmp);

        std::priority_queue<int> pq;
        cnt = 0;

        for(i = 0; P < L && i < N; ++i) {
            if(L - A[i].pos <= P) {
                pq.push(A[i].val);
            } else if(!pq.empty()) {
                P += pq.top(); pq.pop();
                ++cnt; --i;
            } else break;
        }
        
        while(P < L && !pq.empty()) {
            P += pq.top();
            pq.pop(); ++cnt;
        }

        if(P < L) cnt = -1;
        printf("%d\n", cnt);
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// int n, L, P;
// struct station
// {
//     int dis;
//     int fuel;
// };
// vector<station> dat;
// int comp(station &x,station &y)
// {
//     return x.dis > y.dis;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     dat.resize(n + 5);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> dat[i].dis >> dat[i].fuel;
//     }
//     sort(&dat[1], &dat[n + 1], comp);
//     cin >> L >> P;
//     deque<int> queue;
//     int tag = 1;
//     int total = 0;
//     while (L - P > 0 && tag <= n)
//     {
//         for (; tag <= n && dat[tag].dis >= L - P; tag++)
//         {
//             while (!queue.empty())
//             {
//                 if (dat[queue.back()].fuel <= dat[tag].fuel)
//                 {
//                     queue.pop_back();
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             queue.push_back(tag);
//         }
//         tag = queue.front();
//         queue.pop_front();
//         P = (P - L + dat[tag].dis) + dat[tag].fuel;
//         L = dat[tag].dis;
//         tag++;
//         total++;
//     }
//     cout << ((L - P <= 0) ? total : -1) << endl;

//     return 0;
// }