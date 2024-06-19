// 没有保存最短路径数为全局变量，导致没法最优性剪枝
#include <bits/stdc++.h>
using namespace std;
int w, h;
const int MAXN = 75;
char mp[MAXN + 2][MAXN + 2];
int minStep, dis[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool mark[MAXN + 2][MAXN + 2];
void search(int currentX, int currentY, int endX, int endY, int step, int f)
{
    if (step > minStep)
        return;
    if (currentX == endX && currentY == endY)
    {
        if (step < minStep)
            minStep = step;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = currentX + dis[i][0];
        int dy = currentY + dis[i][1];
        if ((dx > -1 && dx < w + 2 && dy > -1 && dy < h + 2) && ((mark[dy][dx] == false && mp[dy][dx] == ' ') || (dx == endX && dy == endY && mp[dy][dx] == 'X')))
        {
            mark[dy][dx] = true;
            if (i == f)
                search(dx, dy, endX, endY, step, i);
            else
                search(dx, dy, endX, endY, step + 1, i);
            mark[dy][dx] = false;
        }
    }
}
int main()
{
    int boardNum = 0;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        boardNum++;
        cout << "Board #" << boardNum << ":" << endl;
        int i, j;
        for (int i = 0; i < MAXN + 2; i++)
        {
            mp[0][i] = ' ';
            mp[i][0] = ' ';
        }
        for (i = 1; i <= h; i++)
        {
            getchar();
            for (j = 1; j <= w; j++)
            {
                mp[i][j] = getchar();
            }
        }
        for (int i = 0; i <= w; i++)
        {
            mp[h + 1][i + 1] = ' ';
        }
        for (int i = 0; i <= h; i++)
        {
            mp[i + 1][w + 1] = ' ';
        }
        int startX, startY, endX, endY, count = 0;
        while ((cin >> startX >> startY >> endX >> endY) && startX > 0)
        {
            count++;
            minStep = 1000000;
            memset(mark, false, sizeof(mark));
            search(startX, startY, endX, endY, 0, -1);
            if (minStep < 1000000)
                cout << "Pair " << count << ": " << minStep << " segments." << endl;
            else
                cout << "Pair " << count << ": impossible." << endl;
        }
        cout << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int board[80][80];
// int vis[80][80];
// int X1, X2, Y1, Y2;
// int w, h;
// #define check(y,x) (x>=0&&x<=h+1&&y>=0&&y<=w+1&&!board[x][y])
// #define INF 0x7777777
// int dx[4]={0,1,0,-1};
// int dy[4]={1,0,-1,0};
// int solve(int x1,int y1,int dir){
//     int tmp = INF;
//     int new_dir = 0;
//     for(int i=0;i<4;i++){
//         if(check(x1+dx[i],y1+dy[i])&&!vis[y1+dy[i]][x1+dx[i]]){
//             new_dir = ((i<2)?1:-1);
//             vis[y1+dy[i]][x1+dx[i]]=1;
//             tmp = min(tmp,((new_dir*dir<=0)?1:0)+solve(x1+dx[i],y1+dy[i],new_dir));
//             vis[y1+dy[i]][x1+dx[i]]=0;
//         }else if(x1+dx[i]==X2&&y1+dy[i]==Y2){
//             new_dir = ((i<2)?1:-1);
//             return ((new_dir*dir<=0)?1:0);
//         }
//     }
//     return tmp;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     while (cin >> w >> h && w)
//     {
//         memset(vis,0,sizeof(vis));
//         memset(board,0,sizeof(board));
//         cout << "Board #" << (t++) << ":" << endl;
//         string tmp;
//         getline(cin,tmp);
//         for(int i=1;i<=h;i++){
//             getline(cin,tmp);
//             int l = tmp.length();
//             for(int j=1;j<=l;j++)
//                 board[i][j]=((tmp[j-1]==' ')?0:1);
//         }
//         int num = 1;
//         while (cin >> X1 >> Y1 >> X2 >> Y2 && X1)
//         {
//             int res = solve(X1,Y1,0);
//             if(res!=INF)
//                 cout<<"Pair "<<(num++)<<": "<<res<<" segments."<<endl;
//             else
//                 cout<<"Pair "<<(num++)<<": "<<"impossible."<<endl;
//         }
//     }
//     return 0;
// }