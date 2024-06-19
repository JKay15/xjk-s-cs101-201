#include <bits/stdc++.h>
using namespace std;
int cnt,n,board[8][8];
string ans;
bool check(int x,int y){
    int s=max(0,x-y),e=max(0,y-x);
    while(s<8&&e<8){
        if(board[s][e])return 0;
        s++,e++;
    }
    s=min(7,x+y),e=(x+y>7)?(y-(7-x)):0;
    while(s>=0&&e<8){
        if(board[s][e])return 0;
        s--,e++;
    }
    return 1;
}
void dfs(int x,int col,string res){
    if(ans!="")return ;
    if(x==8){
        cnt++;
        if(cnt==n)ans=res;
        return ;
    }
    for(int i=0;i<8;i++){
        if(ans!="")return ;
        if(!(col&(1<<i))&&check(x,i)){
            board[x][i]=1;
            dfs(x+1,col+(1<<i),res+char(i+'1'));
            board[x][i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(board,0,sizeof(board));
        ans="",cnt=0;
        dfs(0,0,"");
        cout<<ans<<"\n";
    }
    return 0;
}