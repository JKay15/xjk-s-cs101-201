//第一次正式写字典树，体验还行
//但是中间又出现了变量初始化的问题，以及变量赋值的粗心问题，这个就很不好了
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int cnt=1,c,l,w;
int tree[maxn][26];
int end1[maxn];
char board[1005][1005];
vector<string> cont;
unordered_map<string,pair<int,pair<int,char>>> ans;
char dir[8]={'A','B','C','D','E','F','G','H'};
int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
#define check(x,y)(x>=0&&x<l&&y>=0&&y<c)
void build(){
    cnt=1;
}
void insert(string word){
    int cur=1,l=word.length();
    for(int i=0;i<l;i++){
        int path=word[i]-'A';
        if(tree[cur][path]==0)tree[cur][path]=++cnt;
        cur=tree[cur][path];
    }   
    end1[cur]++;
}

void dfs(int x,int y){
    //这里注意cur要在每次更换方向时重置为1，xx、yy也要重置为x和y，pat也是一个道理
    //不要把这些量的初始化写在for循环外面
    for(int i=0;i<8;i++){
        int cur=1;
        int xx=x,yy=y;
        string pat="";
        while(check(xx,yy)){
            int path=board[xx][yy]-'A';
            if(tree[cur][path]){
                pat+=board[xx][yy];
                cur=tree[cur][path];
                if(end1[cur]){
                    ans[pat]={x,{y,dir[i]}};
                }
            }else break;
            //这里之前写了xx=x+dx[i]，这显然是不对的，要在xx本身上加dx[i]，yy也是同理
            xx+=dx[i],yy+=dy[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    build();
    cin>>l>>c>>w;
    for(int i=0;i<l;i++)
    for(int j=0;j<c;j++)cin>>board[i][j];
    string tmp;
    for(int i=0;i<w;i++){
        cin>>tmp;
        cont.push_back(tmp);
        insert(tmp);
    }
    for(int i=0;i<l;i++)
    for(int j=0;j<c;j++){
        dfs(i,j);
    }
    for(auto x:cont)cout<<ans[x].first<<" "<<ans[x].second.first<<" "<<ans[x].second.second<<"\n";
    return 0;
}