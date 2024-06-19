#include <bits/stdc++.h>
using namespace std;
int n,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
struct node{
    int x1,y1,x2,y2;
    node(int a=0,int b=0,int c=0,int d=0):x1(a),y1(b),x2(c),y2(d){}
};
int board[35][35];
bool vis[35][35];
#define check(x,y) (x>0&&x<=n&&y>0&&y<=n)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    node root;
    //这里最好不要从0开始存，会出现root.x1存完之后还是0的情况，就没办法存x2了
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        cin>>board[i][j];
        if(board[i][j]==5&&!root.x1){
            root.x1=i;root.y1=j;
            vis[i][j]=1;
        }else if(board[i][j]==5&&root.x1){
            root.x2=i;root.y2=j;
        }
    }
    queue<node> q;
    q.push(root);
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx1=cur.x1+dx[i],yy1=cur.y1+dy[i],xx2=cur.x2+dx[i],yy2=cur.y2+dy[i];
            if(check(xx1,yy1)&&check(xx2,yy2)&&board[xx1][yy1]!=1&&board[xx2][yy2]!=1&&!vis[xx1][yy1]){
                vis[xx1][yy1]=1;
                if(board[xx1][yy1]==9||board[xx2][yy2]==9){
                    cout<<"yes\n";
                    return 0;
                }
                q.push(node{xx1,yy1,xx2,yy2});
            }
        }
    }
    cout<<"no\n";
    return 0;
}