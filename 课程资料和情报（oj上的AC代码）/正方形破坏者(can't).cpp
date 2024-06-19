// //方法1
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int MAX_SIZE = 5;
// const int MAX_STK = 60;
// typedef unsigned long long ULL;
// class CoverInit
// {
// private:
//     static int m_size; // Number of the stick on the top of the grid [row][col].
//     static int m_up[MAX_SIZE][MAX_SIZE];
//     static void initUp()
//     {
//         for (int i = 0; i < m_size; i++)
//         {
//             m_up[i][0] = i * (2 * m_size + 1);
//             for (int j = 1; j < m_size; j++)
//             {
//                 m_up[i][j] = m_up[i][j - 1] + 1;
//             }
//         }
//     }
//     static void initSqr(int firstStick, int size, ULL mask, ULL *cover)
//     {
//         int gap = 2 * m_size + 1;
//         int num = firstStick; // The upper and the lower edges.
//         for (int i = 0; i < size; i++)
//         {
//             cover[num] |= mask;
//             cover[num + size * gap] |= mask;
//             num++;
//         }
//         num = firstStick + m_size; // The left and the right edges.
//         for (int i = 0; i < size; i++)
//         {
//             cover[num] |= mask;
//             cover[num + size] |= mask;
//             num += gap;
//         }
//     }

// public:
//     static void initCover(int size, ULL *cover, int stkCnt)
//     {
//         m_size = size;
//         initUp();
//         memset(cover, 0, stkCnt * sizeof(ULL));
//         ULL mask = 1ULL;
//         for (int sqrSize = 1; sqrSize <= m_size; sqrSize++)
//         {
//             for (int i = 0; i <= m_size - sqrSize; i++)
//             {
//                 for (int j = 0; j <= m_size - sqrSize; j++)
//                 {
//                     int up = m_up[i][j];
//                     initSqr(up, sqrSize, mask, cover);
//                     mask <<= 1;
//                 }
//             }
//         }
//     }
// };
// int CoverInit::m_size;
// int CoverInit::m_up[MAX_SIZE][MAX_SIZE];
// class Solution
// {
// private:
//     ULL m_cover[MAX_STK];
//     bool m_stick[MAX_STK];
//     ULL m_universal;
//     int m_sqrCnt;
//     int m_stkCnt;
//     int m_minStk;
//     ULL m_remainCov[MAX_STK];
//     void dfs(char stkCnt, char lastStk, ULL cover)
//     {
//         if (cover == m_universal)
//         {
//             m_minStk = stkCnt;
//         }
//         else
//         {
//             if (stkCnt < m_minStk && (m_remainCov[lastStk + 1] | cover) == m_universal)
//             {
//                 for (int i = lastStk + 1; i < m_stkCnt; i++)
//                 {
//                     if ((m_cover[i] | cover) > cover)
//                     {
//                         dfs(stkCnt + 1, i, cover | m_cover[i]);
//                     }
//                 }
//             }
//         }
//     }
//     void init(int size)
//     {
//         m_stkCnt = 2 * size * (size + 1);
//         CoverInit::initCover(size, m_cover, m_stkCnt);
//         int sqrCnt = 0;
//         for (int i = 1; i <= size; i++)
//         {
//             sqrCnt += i * i;
//         }
//         m_universal = 1ULL;
//         for (int i = 1; i < sqrCnt; i++)
//         {
//             m_universal <<= 1;
//             m_universal += 1ULL;
//         }
//         for (int i = 0; i < m_stkCnt; i++)
//         {
//             m_stick[i] = true;
//         }
//     }
//     void modifyData()
//     {
//         for (int i = 0; i < m_stkCnt; i++)
//         {
//             if (!m_stick[i])
//             {
//                 m_universal &= ~m_cover[i];
//             }
//         }
//         for (int i = 0; i < m_stkCnt; i++)
//         {
//             m_cover[i] &= m_universal;
//         }
//         for (int i = 0; i < m_stkCnt; i++)
//         {
//             if (m_stick[i])
//             {
//                 for (int j = 0; j < m_stkCnt; j++)
//                 {
//                     if (j != i && m_stick[j] && m_cover[j] == (m_cover[j] & m_cover[i]))
//                     {
//                         m_stick[j] = false;
//                     }
//                 }
//             }
//         }
//         int cnt = 0;
//         for (int i = 0; i < m_stkCnt; i++)
//         {
//             if (m_stick[i])
//             {
//                 m_cover[cnt] = m_cover[i];
//                 cnt++;
//             }
//         }
//         m_stkCnt = cnt;
//         m_remainCov[m_stkCnt - 1] = m_cover[m_stkCnt - 1];
//         for (int i = m_stkCnt - 2; i >= 0; i--)
//         {
//             m_remainCov[i] = m_remainCov[i + 1] | m_cover[i];
//         }
//     }

// public:
//     void input()
//     {
//         int size;
//         cin >> size;
//         init(size);
//         int rmCnt;
//         cin >> rmCnt;
//         for (int i = 0; i < rmCnt; i++)
//         {
//             int rm;
//             cin >> rm;
//             m_stick[rm - 1] = false;
//         }
//     }
//     void search()
//     {
//         modifyData();
//         m_minStk = m_stkCnt < 9 ? m_stkCnt : 9;
//         dfs(0, -1, 0ULL);
//         cout << m_minStk << endl;
//     }
// };
// int main()
// {
//     Solution solution;
//     int caseCnt;
//     cin >> caseCnt;
//     for (int i = 0; i < caseCnt; i++)
//     {
//         solution.input();
//         solution.search();
//     }
//     return 0;
// }
// //方法2
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;

// const int N = 61;      // 网格最大是 5 * 5 的，其中最多会有 5 * (5 + 1) * 2 = 60 个正方形，所以要开到 61
// int n, idx;            // n 为网格规模，idx 为正方形数量
// int max_depth;         // IDA* 的 max_depth
// vector<int> square[N]; // 存每个正方形边上的火柴的编号
// bool used[N];          // 存每个火柴是否已经被破坏
// // 新加一个左上角坐标为 (r, c)，边长为 len 的正方形
// void add(int r, int c, int len)
// {
//     int d = n << 1 | 1;  // 由于用到的 2n + 1 比较多，这里先用一个变量代替掉 2n + 1
//     vector<int> &s = square[idx];
//     s.clear(); // 有多组测试数据，需要上一组数据的内容清空
//     for (int i = 0; i < len; i ++ )
//     {
//         s.push_back(1 + r * d + c + i);               // 上边第 i 个
//         s.push_back(1 + (r + len) * d + c + i);       // 下边第 i 个
//         s.push_back(1 + n + r * d + c + i * d);       // 左边第 i 个
//         s.push_back(1 + n + r * d + c + i * d + len); // 右边第 i 个
//     }
//     idx ++ ;
// }
// // 判断正方形 s 是否完整
// bool check(vector<int> &s)
// {
//     for (int i = 0; i < (int)s.size(); i ++ )
//         if (used[s[i]]) 
// 			return false; // 如果其中有一条边已经被破坏了，那么说明不完整
//     return true; // 如果每条边都没被破坏，说明完整
// }
// // 估价函数
// int f()
// {
//     static bool backup[N]; // 由于要改动 used，需要先新建一个备份数组
//     memcpy(backup, used, sizeof used); // 将 used 复制到备份数组中
//     int res = 0;
//     for (int i = 0; i < idx; i ++ ) // 枚举所有正方形
//         if (check(square[i]))       // 如果某个正方形是完整的，
//         {
//             res ++ ;                // 那么 res ++ ，并将该正方形所有的边都删去
//             for (int j = 0; j < (int)square[i].size(); j ++ )
//                 used[square[i][j]] = true;
//         }
//     memcpy(used, backup, sizeof used); // 复制回来
//     return res;
// }

// // IDA*
// bool dfs(int depth)
// {
//     if (depth + f() > max_depth) return false;
//     for (int i = 0; i < idx; i ++ ) // 枚举所有的正方形
//         if (check(square[i]))       // 如果第 i 个正方形还没被破坏
//         {// 那么枚举该正方形的所有边编号，去掉该边并继续爆搜
//             for (int j = 0; j < (int)square[i].size(); j ++ )
//             {
//                 used[square[i][j]] = true;
//                 if (dfs(depth + 1)) return true;
//                 used[square[i][j]] = false;
//             }
//             return false;// 如果每条边都爆搜不成功，那么说明删掉 max_depth 个火柴无法破坏该正方形
//         }
//     return true; // 如果所有的正方形都被破坏了，返回 true
// }

// int main()
// {
//     int T;scanf("%d",&T);
//     while (T -- )
//     {
//         scanf("%d", &n), idx = 0; // 初始化 idx
//         memset(used, false, sizeof used); // 初始化 used
//         for (int len = 1; len <= n; len ++ ) // 枚举 len, r, c，预处理每个正方形
//             for (int r = 0; r + len <= n; r ++ )
//                 for (int c = 0; c + len <= n; c ++ )
//                     add(r, c, len);
//         int k;scanf("%d", &k);
//         while (k -- )  // 读入所有已经被破坏的边
//         {
//             int x;scanf("%d", &x);
//             used[x] = true;
//         }
//         max_depth = 0; // IDA*
//         while (!dfs(0)) max_depth ++ ;
//         printf("%d\n", max_depth);
//     }
//     return 0;
// }
// //方法3
// #include"stdio.h"
// #include"algorithm"
// #include"string.h"
// #include"iostream"
// #include"cmath"
// #include"queue"
// #include"map"
// #include"vector"
// #include"string"
// using namespace std;
// #define RN 70
// #define CN 70
// #define N 70*70
// int fuck[123];
// vector<int>edge[123];
// struct DLX
// {
//     int n,m,C;
//     int U[N],D[N],L[N],R[N],Row[N],Col[N];
//     int H[RN],S[CN],cnt,ans[RN];
//     void init(int _n,int _m)
//     {
//         n=_n;
//         m=_m;
//         for(int i=0; i<=m; i++)
//         {
//             S[i]=0;
//             U[i]=D[i]=i;
//             L[i]=(i==0?m:i-1);
//             R[i]=(i==m?0:i+1);
//         }
//         C=m;
//         for(int i=1; i<=n; i++) H[i]=-1;
//     }
//     void link(int x,int y)
//     {
//         C++;
//         Row[C]=x;
//         Col[C]=y;
//         S[y]++;
//         U[C]=U[y];
//         D[C]=y;
//         D[U[y]]=C;
//         U[y]=C;
//         if(H[x]==-1) H[x]=L[C]=R[C]=C;
//         else
//         {
//             L[C]=L[H[x]];
//             R[C]=H[x];
//             R[L[H[x]]]=C;
//             L[H[x]]=C;
//         }
//     }
//     void del(int x)
//     {
//         for(int i=D[x]; i!=x; i=D[i])
//         {
//             R[L[i]]=R[i];
//             L[R[i]]=L[i];
//         }
//     }
//     void rec(int x)
//     {
//         for(int i=U[x]; i!=x; i=U[i])
//         {
//             R[L[i]]=i;
//             L[R[i]]=i;
//         }
//     }
//     int used[CN];
//     int h()
//     {
//         int sum=0;
//         for(int i=R[0]; i!=0; i=R[i]) used[i]=0;
//         for(int i=R[0]; i!=0; i=R[i])
//         {
//             if(used[i]==0)
//             {
//                 sum++;
//                 used[i]=1;
//                 for(int j=D[i]; j!=i; j=D[j]) for(int k=R[j]; k!=j; k=R[k]) used[Col[k]]=1;
//             }
//         }
//         return sum;
//     }
//     void dance(int x)
//     {
//         if(x+h()>=cnt) return ;
//         if(R[0]==0)
//         {
//             cnt=min(cnt,x);
//             return ;
//         }
//         int now=R[0];
//         for(int i=R[0]; i!=0; i=R[i])
//         {
//             if(S[i]<S[now])
//                 now=i;
//         }
//         for(int i=D[now]; i!=now; i=D[i])
//         {
//             del(i);
//             for(int j=R[i]; j!=i; j=R[j]) del(j);
//             dance(x+1);
//             for(int j=L[i]; j!=i; j=L[j]) rec(j);
//             rec(i);
//         }
//         return ;
//     }
//     void DeleteTrick(int r)  //强行先放入某行。
//     {
//         if(H[r] == -1) return ;
//         for(int i = D[H[r]]; i != H[r]; i = D[i])
//         {
//             if(H[Row[i]] == i)
//             {
//                 if(R[i] == i)
//                 {
//                     H[Row[i]] = -1;
//                 }
//                 else
//                 {
//                     H[Row[i]] = R[i];
//                 }
//             }
//             L[R[i]] = L[i];
//             R[L[i]] = R[i];
//         }
 
//         for(int i = R[H[r]]; i != H[r]; i = R[i])
//         {
//             for(int j = D[i]; j != i; j = D[j])
//             {
//                 if(H[Row[j]] == j)
//                 {
//                     if(R[j] == j)
//                     {
//                         H[Row[j]] = -1;
//                     }
//                     else
//                     {
//                         H[Row[j]] = R[j];
//                     }
//                 }
//                 L[R[j]] = L[j];
//                 R[L[j]] = R[j];
//             }
//         }
//     }
// } dlx;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m;
//         scanf("%d%d",&n,&m);
//         for(int i=0; i<m; i++) scanf("%d",&fuck[i]);
//         for(int i=0; i<=70; i++) edge[i].clear();
//         int sum=0;
//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=n; j++)
//             {
//                 int num=(i-1)*(n+n+1)+j;
//                 int lit=min(n-i+1,n-j+1);
//                 for(int k=1; k<=lit; k++)
//                 {
//                     sum++;
//                     int up,down,left,right;
//                     up=num;
//                     left=num+n;
//                     right=left+k;
//                     down=up+k*(n+n+1);
//                     for(int o=0; o<k; o++)
//                     {
//                         edge[up+o].push_back(sum);
//                         edge[left+o*(n+n+1)].push_back(sum);
//                         edge[right+o*(n+n+1)].push_back(sum);
//                         edge[down+o].push_back(sum);
//                     }
//                 }
//             }
//         }
//         dlx.init(2*n*(n+1),sum);
 
//         for(int i=1; i<=2*n*(n+1); i++)
//         {
//             for(int j=0; j<(int)edge[i].size(); j++) dlx.link(i,edge[i][j]);
//         }
//         int fff[123];
//         memset(fff,0,sizeof(fff));
//         //for(int j=0; j<(int)edge[1].size(); j++) printf("%d ",edge[1][j]);
//         //puts("");
//         for(int i=0; i<m; i++)
//         {
//             dlx.DeleteTrick(fuck[i]);
//         }
//         dlx.cnt=999;
//         dlx.dance(0);
//         printf("%d\n",dlx.cnt);
//     }
//     return 0;
// }
//方法4
#include<bits/stdc++.h> 
using namespace std;

int T, n, k, totstick, totsquare, neibor, ans, maxd, exi[65], temp[65];

vector <int> stick[65];     // stick[i]记录每条边包含的正方形
vector <int> square[65];    //  square[i]记录每个正方形包含的边

int h()//gu'jiguji
{
    int res = 0;
    for(int i = 1; i <= totsquare; i++) temp[i] = exi[i];
    for(int i = 1; i <= totsquare; i++) if(!temp[i])
    {
        res ++;
        temp[i] -= square[i].size();
        for(int j = 0; j < square[i].size(); j++) 
        for(int l = 0; l < stick[square[i][j]].size(); l++)
        {
            temp[stick[square[i][j]][l]] --;
        }
    }
    return res;
}

bool dfs(int sum)
{
    if(sum+h() >= maxd) return 0;

    int tmp = 1;
    while(exi[tmp] < 0 && tmp <= totsquare) tmp++;  // choose a square (tmp)
    if(tmp > totsquare) {ans = min(sum, ans); return 1;}

    for(int i = 0; i < square[tmp].size(); i++)  // choose which in tmp to destroy
    {
        int sti = square[tmp][i];
        for(int j = 0; j < stick[sti].size(); j++) exi[stick[sti][j]]--;

        if(dfs(sum+1)) return 1;

        for(int j = 0; j < stick[sti].size(); j++) exi[stick[sti][j]]++;
    }
    return 0;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        totstick = (n+1)*n*2; totsquare = 0; neibor = n*2+1; 

        for(int i = 1; i < 65; i++)
        {
            stick[i].clear(); square[i].clear();
        }   

        for(int sz = 1; sz <= n; sz++)         //枚举正方形的边长 
        for(int i = 1; (i-1)/neibor+sz <= n; i += neibor)   //枚举行
        for(int j = i; j-i+sz <= n; j++)    //枚举列 
        {
             totsquare ++;
            for(int l = j; l-j < sz; l++)  //枚举正方形的上边 
            {
                square[totsquare].push_back(l);   
                square[totsquare].push_back(l+sz*neibor);  //上边对应的下边 
                stick[l].push_back(totsquare);
                stick[l+sz*neibor].push_back(totsquare);   
            }
            for(int l = j+n; (l-j-sz)/neibor < sz; l += neibor)
            {
                square[totsquare].push_back(l);
                square[totsquare].push_back(l+sz);
                stick[l].push_back(totsquare);
                stick[l+sz].push_back(totsquare);       
            }
        }

        memset(exi, 0, sizeof exi);
        for(int i = 1; i <= k; i++)
        {
            int t; scanf("%d", &t);
            for(int j = 0; j < stick[t].size(); j++)
            {
                exi[stick[t][j]]--;
            }
            totstick --;
        }

        ans = totstick;
        cout<<ans<<endl;
        for(int i=1;i<=totstick;i++){
            for(int j=0;j<stick[i].size();j++)cout<<stick[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=totsquare;i++){
            for(int j=0;j<square[i].size();j++)cout<<square[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=totsquare;i++)cout<<exi[i]<<" ";
        cout<<endl;
        // for(maxd = 1; ; maxd++) if(dfs(0)) break;
        // printf("%d\n", ans);
    }
    return 0;
}