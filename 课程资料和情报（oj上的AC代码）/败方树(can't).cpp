#include <bits/stdc++.h>
using namespace std;
int n, m, _index, val;
int LowExt, offset;     
int ini[1000], b[2000]; 
int loser(int a, int b) 
{
    return ini[a] > ini[b] ? a : b;
}
int winner(int a, int b)
{
    return ini[a] > ini[b] ? b : a;
}
void play(int father, int left, int right) 
{
    int temp1 = 0, temp2 = 0;
    b[father] = loser(left, right);
    temp1 = winner(left, right);
    while (father > 1 && father % 2 == 1) 
    {
        temp2 = winner(temp1, b[father / 2]);
        b[father / 2] = loser(temp1, b[father / 2]); 
        temp1 = temp2;
        father /= 2; 
    }
    b[father / 2] = temp1; 
}
void replay(int i)
{
    int father = 0;
    if (i <= LowExt)
        father = (i + offset) / 2;
    else
        father = (i - LowExt + n - 1) / 2;
    b[0] = winner(i, b[father]);   
    b[father] = loser(i, b[father]); 
    for (; (father / 2) >= 1; father /= 2)
    {
        int temp = 0;
        temp = winner(b[father / 2], b[0]); 
        b[father / 2] = loser(b[father / 2], b[0]);
        b[0] = temp;
    }
}
void make(int *a) 
{
    int i = 0, s = 0, size = n;
    for (s = 1; s * 2 <= n - 1; s += s)
        ; 
    LowExt = 2 * (size - s);
    offset = 2 * s - 1;
    for (i = 2; i <= LowExt; i += 2)play((offset + i) / 2, i - 1, i); 
    if (size % 2) 
    {
        play(n / 2, b[(n - 1) / 2], LowExt + 1); 
        i = LowExt + 3;
    }
    else i = LowExt + 2;
    for (; i <= n; i += 2)play((i - LowExt + n - 1) / 2, i - 1, i);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%d", &ini[i]);
    make(b);
    for (int i = 0; i < n; i++)printf("%d ", ini[b[i]]);
    printf("\n");
    while (m--)
    {
        scanf("%d%d", &_index, &val);
        ini[_index + 1] = val;
        replay(_index + 1);
        for (int i = 0; i < n; i++)printf("%d ", ini[b[i]]);
        printf("\n");
    }
    return 0;
}