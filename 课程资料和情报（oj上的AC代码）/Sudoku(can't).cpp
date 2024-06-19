#include <bits/stdc++.h>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 11;
int maze[maxn][maxn];
bool grid[maxn][maxn];                //9个数字在每个3*3方格里的出现次数
bool row[maxn][maxn], col[maxn][maxn];//9个数字在每行/列里的出现次数
bool Dfs(int x, int y){
    if(x==10) return true;
    bool flag = false;
    if(maze[x][y]){                  //如果该点已有数
        if(y==9) flag = Dfs(x+1, 1); //搜索顺序
        else flag = Dfs(x, y+1);
        return flag;
    }

    int g = 3*((x-1)/3)+(y-1)/3+1;
    for(int i = 1; i <= 9; i++){
        if(!row[x][i] && !col[y][i] && !grid[g][i]){
            row[x][i] = col[y][i] = grid[g][i] = true;
            maze[x][y] = i;
            if(y==9) flag = Dfs(x+1, 1);
            else flag = Dfs(x, y+1);
            if(flag) return true;     //找到了解
            maze[x][y] = 0;
            row[x][i] = col[y][i] = grid[g][i] = false;//回溯
        }
    }
    return false;
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        ms(grid, 0); ms(row, 0); ms(col, 0);
        char input;
        for(int i = 1; i <= 9; i++)
            for(int j = 1; j <= 9; j++){
                cin >> input;
                maze[i][j] = input-'0';
                if(maze[i][j]){
                    int g = 3*((i-1)/3)+(j-1)/3+1;
                    grid[g][maze[i][j]] = true;      //初始化剪枝数组
                    row[i][maze[i][j]] = true;
                    col[j][maze[i][j]] = true;
                }
            }
        Dfs(1, 1);
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
	return 0;
}
//不知道是哪里挂了，总之是不咋地
// #include <bits/stdc++.h>
// using namespace std;
// int a[9][9],vis[9][9],col[9],row[9],cell[9],total,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
// #define zero(x) memset(x,0,sizeof(x))
// #define check(x,y) (x>=0&&x<9&&y>=0&&y<9)
// #define do(i,j) row[i]|=(1<<a[i][j]);col[j]|=(1<<a[i][j]);cell[3*(i/3)+j/3]|=(1<<a[i][j])
// #define undo(i,j) row[i]^=(1<<a[i][j]);col[j]^=(1<<a[i][j]);cell[3*(i/3)+j/3]^=(1<<a[i][j])
// void dfs(int x,int y){
//     if(total==81)return ;
//     if(a[x][y])
//     for(int i=0;i<4;i++){
//         int xx=x+dx[i],yy=y+dy[i];
//         if(check(xx,yy)&&!vis[xx][yy]){
//             vis[xx][yy]=1;
//             dfs(xx,yy);
//             vis[xx][yy]=0;
//         }
//         if(total==81)return;
//     }
//     else
//     for(int i=1;i<=9;i++){
//         if(!(cell[3*(x/3)+y/3]&(1<<i))&&!(row[x]&(1<<i))&&!(col[y]&(1<<i))){
//             a[x][y]=i;
//             do(x,y);
//             total++;
//             for(int j=0;j<4;j++){
//                 int xx=x+dx[j],yy=y+dy[j];
//                 if(check(xx,yy)&&!vis[xx][yy]){
//                     vis[xx][yy]=1;
//                     dfs(xx,yy);
//                     vis[xx][yy]=0;
//                 }
//                 if(total==81)return;
//             }
//             total--;
//             undo(x,y);
//             a[x][y]=0;
//         }
//     }
// }
// int main(){
//     freopen("res.txt","w",stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         zero(a);zero(col);zero(row);zero(vis);
//         for(int i=0;i<9;i++)
//         for(int j=0;j<9;j++){
//             char t;
//             cin>>t;a[i][j]=t-'0';   
//             do(i,j);
//             total+=(a[i][j]!=0);
//         }
//         vis[0][0]=1;
//         dfs(0,0);
//         for(int i=0;i<9;i++)
//         for(int j=0;j<9;j++)cout<<a[i][j]<<((j==8)?"\n":"");
//     }
//     return 0;
// }