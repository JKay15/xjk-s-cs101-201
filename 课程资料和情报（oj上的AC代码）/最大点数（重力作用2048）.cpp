//照抄题目里面给的移动代码，之后就是最简单的dfs回溯了，不要花太多时间在抽象上，考试的时候划不来
#include <bits/stdc++.h>
using namespace std;
int m,n,p,board[15][15],ans;
int down(){
    bool changed=0;
    while(1){
        bool c=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++){
            if(board[j][i]&&!board[j+1][i]){
                board[j+1][i]=board[j][i];
                board[j][i]=0;
                c=1;
            }
        }
        changed=c;
        if(!c)break;
    }
    for(int i=1;i<=n;i++)
    for(int j=m;j>1;j--){
        if(board[j][i]==board[j-1][i]){
            board[j][i]*=2;
            board[j-1][i]=0;
            changed=1;
        }
    }
    while(1){
        bool c=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++){
            if(board[j][i]&&!board[j+1][i]){
                board[j+1][i]=board[j][i];
                board[j][i]=0;
                c=1;
            }
        }
        if(!c)break;
    }
    return changed;
}
int up(){
    bool changed=0;
    while(1){
        bool c=0;
        for(int i=1;i<=n;i++)
        for(int j=m;j>1;j--){
            if(board[j][i]&&!board[j-1][i]){
                board[j-1][i]=board[j][i];
                board[j][i]=0;
                c=1;
            }
        }
        changed=c;
        if(!c)break;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<m;j++){
        if(board[j][i]==board[j+1][i]){
            board[j][i]*=2;
            board[j+1][i]=0;
            changed=1;
        }
    }
    while(1){
        bool c=0;
        for(int i=1;i<=n;i++)
        for(int j=m;j>1;j--){
            if(board[j][i]&&!board[j-1][i]){
                board[j-1][i]=board[j][i];
                board[j][i]=0;
                c=1;
            }
        }
        if(!c)break;
    }
    return changed;
}
int right(){
    bool changed=0;
    while(1){
        bool c=0;
        for(int i=1;i<=m;i++)
        for(int j=1;j<n;j++){
            if(board[i][j]&&!board[i][j+1]){
                board[i][j+1]=board[i][j];
                board[i][j]=0;
                c=1;
            }
        }
        changed=c;
        if(!c)break;
    }
    for(int i=1;i<=m;i++)
    for(int j=n;j>1;j--){
        if(board[i][j]==board[i][j-1]){
            board[i][j]*=2;
            board[i][j-1]=0;
            changed=1;
        }
    }
    while(1){
        bool c=0;
        for(int i=1;i<=m;i++)
        for(int j=1;j<n;j++){
            if(board[i][j]&&!board[i][j+1]){
                board[i][j+1]=board[i][j];
                board[i][j]=0;
                c=1;
            }
        }
        if(!c)break;
    }
    return changed;
}
int left(){
    bool changed=0;
    while(1){
        bool c=0;
        for(int i=1;i<=m;i++)
        for(int j=n;j>1;j--){
            if(board[i][j]&&!board[i][j-1]){
                board[i][j-1]=board[i][j];
                board[i][j]=0;
                c=1;
            }
        }
        changed=c;
        if(!c)break;
    }
    for(int i=1;i<=m;i++)
    for(int j=1;j<n;j++){
        if(board[i][j]==board[i][j+1]){
            board[i][j]*=2;
            board[i][j+1]=0;
            changed=1;
        }
    }
    while(1){
        bool c=0;
        for(int i=1;i<=m;i++)
        for(int j=n;j>1;j--){
            if(board[i][j]&&!board[i][j-1]){
                board[i][j-1]=board[i][j];
                board[i][j]=0;
                c=1;
            }
        }
        if(!c)break;
    }
    return changed;
}
int max_e(){
    int ans=0;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)ans=max(ans,board[i][j]);
    return ans;
}
int dfs(int res){
    if(!res)return max_e();
    int copy[15][15],ans=max_e();
    memcpy(copy,board,15*15*sizeof(int));
    if(left())ans=max(ans,dfs(res-1));
    memcpy(board,copy,15*15*sizeof(int));
    if(right())ans=max(ans,dfs(res-1));
    memcpy(board,copy,15*15*sizeof(int));
    if(up())ans=max(ans,dfs(res-1));
    memcpy(board,copy,15*15*sizeof(int));
    if(down())ans=max(ans,dfs(res-1));
    return ans;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)cin>>board[i][j];
    cout<<dfs(p);
    return 0;
}