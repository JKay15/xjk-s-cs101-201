// 不明白为什么并查集可以我不行，而且不是超时的问题——是题目说了空树也算树，但我没意识到
//甚至不用判断环
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <unordered_map>
using namespace std;
int tmp1, tmp2;
unordered_map<int,int> tree;
int check()
{
    if (tree.size() == 0)
        return 1;
    int total = 0;
    int tag = 0;
    std::for_each(tree.begin(), tree.end(), [&total, &tag](pair<int,int> x)
                  {
                      total += x.second;
                      if(x.second>1){
                        tag =1;
                      } });
    if (tag)
        return 0;
    return (total == int(tree.size()) - 1) ? 1 : 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tag = 1;
    while (cin >> tmp1 >> tmp2 && (tmp1 != -1 && tmp2 != -1))
    {
        if (tmp1 == 0)
        {
            if (check())
            {
                cout << "Case " << tag << " is a tree." << endl;
            }
            else
            {
                cout << "Case " << tag << " is not a tree." << endl;
            }
            tag++;
            tree.clear();
        }
        else
        {
            if (tree.find(tmp1) == tree.end())
            {
                tree[tmp1] = 0;
            }
            tree[tmp2]++;
        }
    }
    return 0;
}

// int check1(int ok)
// {
//     if (ok == 2)
//         return 1;
//     if (ok == 1)
//     {
//         for (auto node : tree)
//         {
//             if (node.second.size() > 0)
//             {
//                 int parent = node.second[0];
//                 if (parent == node.first)
//                     return 0;
//                 while (tree[parent].size() > 0)
//                 {
//                     parent = tree[parent][0];
//                     if (parent == node.first)
//                         return 0;
//                 }
//             }
//         }
//         return 1;
//     }
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>

// using namespace std;

// const int N = 100000;
// int f[N + 1], cnt;
// bool visited[N + 1];
// bool nocircleflag;    // 环标记
// int edgecount;      // 边计数

// void UFInit(int n)
// {
//     for(int i = 1; i <=n; i++) {
//         f[i] = i;
//         visited[i] = false;
//     }
//     cnt = n;
//     nocircleflag = true;
//     edgecount = 0;
// }

// int Find(int a) {
//     return a == f[a] ? a : f[a] = Find(f[a]);
// }

// void Union(int a, int b)
// {
//     edgecount++;
//     visited[a] = true;
//     visited[b] = true;

//     a = Find(a);
//     b = Find(b);
//     if (a != b) {
//         f[a] = b;
//         cnt--;
//     } else
//         nocircleflag = false;
// }

// // 唯一树根判定连通性
// bool isconnect() {
//     int root = -1;
//     for( int i=1 ; i<=N ; i++ )
//          if(visited[i]) {
//              if(root == -1)
//                 root = Find(i);
//              else
//                  if(Find(i) != root)
//                      return false;
//          }
//     return true;
// }

// int main()
// {
//     int src, dest, caseno=0;

//     while(scanf("%d%d", &src, &dest) != EOF && (src != -1 || dest != -1)) {
//         if(src==0 && dest==0) {
//             //为空树
//             printf("Case %d is a tree.\n", ++caseno);
//         } else {
//             UFInit(N);

//             Union(src, dest);
//             for(;;) {
//                 scanf("%d%d", &src, &dest);
//                 if( src==0 && dest==0 )
//                     break;

//                 Union(src, dest);
//             }

//             if(nocircleflag && isconnect())
//                 printf("Case %d is a tree.\n", ++caseno);
//             else
//                 printf("Case %d is not a tree.\n", ++caseno);
//         }
//     }

//     return 0;
// }