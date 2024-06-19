//不会做
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
    
//     return 0;
// }
//启发式搜索
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
const int MAXVIS = 363900;
struct State{
    unsigned short s[9];
    int h, g, mh;
    bool operator < (const State& s) const {
        return (g+h)>(s.g+s.h);
    }
    bool operator > (const State& s) const {
        if((g+h) == (s.g+s.h))
            return g < (s.g+s.h);
        return (g+h)<(s.g+s.h);
    }
}st, ed;
priority_queue<State> que;
char now[MAXVIS+5]; int pre[MAXVIS+5];
int _pow[9]; pair<int, int> show[9];
int fx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ppos[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
int fppos[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
char ch[4] = {'d', 'r', 'u', 'l'};
int vis[MAXVIS+5];
int _hash(unsigned short s[]){
    int ret = 0, count =0 ;
    for(int i=0;i<9;i++){
        count = 0;
        for(int j=i+1;j<9;j++)
            count += int(s[j]<s[i]);
        ret += count * _pow[8-i];
    }
    return ret;
}
int _abs(int u){return u>0?u:-u;}
int _h(unsigned short s[]){
    int ret = 0;
    for(int i=0;i<9;i++) if(s[i])
        ret += _abs(ppos[i][0]-show[s[i]].first) + _abs(ppos[i][1]-show[s[i]].second);
    return ret;
}
bool check_pos(const int& a, const int& b){
    if(a > 2 || b > 2 || a < 0 || b < 0) 
        return false;
    return true;
}
stack<char> sta;
void Print(){
    while(!sta.empty()) sta.pop();
    int nowm = ed.mh;
    while(nowm != st.mh) {
        sta.push(now[nowm]);
        nowm = pre[nowm];
    }
    while(!sta.empty()){
        putchar(sta.top());
        sta.pop();
    }
    puts("");
}
void solve(){
    int counter = 0;
    for(int i=0;i<9;i++) if(st.s[i]){
        for(int j=i+1;j<9;j++) if(st.s[j]){
            if(st.s[i] > st.s[j]) counter++;
        }
    }
    if(counter & 1){
        cout<<"unsolvable"<<endl;
        return ;
    }
    memset(vis, 0x3f, sizeof vis);
    while(!que.empty()) que.pop();
    State tmp=st; State t2;
    now[tmp.mh] = 0;
    int pos;
    vis[tmp.mh] = tmp.h = _h(st.s); tmp.g = 0;
    que.push(tmp);
    while(!que.empty()){
        tmp = que.top(); que.pop();
        pos=0;
        if(tmp.mh == ed.mh){
            Print();
            return ;
        }
        if(tmp.g + tmp.h > vis[tmp.mh]) continue;
        while(tmp.s[pos]) pos++;
        for(int i=0;i<4;i++) {
            if(check_pos(ppos[pos][0] + fx[i][0], ppos[pos][1] + fx[i][1])){
                t2 = tmp;
                swap(t2.s[pos], t2.s[fppos[ppos[pos][0] + fx[i][0]][ppos[pos][1] + fx[i][1]]]);
                t2.mh = _hash(t2.s); t2.h = _h(t2.s); (++t2.g);
                if(t2.g + t2.h > vis[t2.mh]) continue;
                vis[t2.mh] = t2.g + t2.h;
                now[t2.mh] = ch[i]; pre[t2.mh] = tmp.mh;
                que.push(t2);
            }
        }
    }
    cout<<"unsolvable"<<endl;
}
int main(){
    char tstr[5];
    _pow[0] = 1;
    for(int i=1;i<=8;i++) _pow[i] = _pow[i-1] * i;
    ed.s[0] = 1; ed.s[1] = 2; ed.s[2] = 3; ed.s[3] = 4;
    ed.s[4] = 5; ed.s[5] = 6; ed.s[6] = 7; ed.s[7] = 8;
    ed.s[8] = 0;
    ed.mh = _hash(ed.s);
    for(int i=0;i<9;i++){show[ed.s[i]] = make_pair(i/3, i%3);}
    while(true){
        for(int i=0;i<9;i++){
            if(scanf("%s", tstr) == EOF) return 0;
            if(tstr[0] != 'x')
                st.s[i]=tstr[0]-'0';
            else st.s[i] = 0;
        }
        st.mh = _hash(st.s);
        if(st.mh == ed.mh) puts("");
        else solve();
    }

    return 0;
}
//bfs+康托展开
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string> 
using namespace std;

struct node
{
    int s[9];
    string road;
    int order;
    int add0;
};
struct node start;
int jiecheng[10],f[2][4]={0,0,-1,1,-1,1,0,0},vis[400005],flag=0;
string anss;
char fang[5]="lrud";
int Contor(int s[],int n)
{
    int order=0;
    for(int i=0;i<n;i++)
    {
        int num=0;
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
            num++;
        }
        order+=num*jiecheng[n-i-1];
    }
    return order+1;
}

void bfs()
{
    queue<struct node>q;
    q.push(start);
    vis[start.order]=1;
    while(!q.empty())
    {
        struct node now=q.front();
        if(now.order==46234)
        {
            flag=1;
            anss=now.road;
            break;
        }
        q.pop();
        int x=now.add0/3;
        int y=now.add0%3;
        int i;
        for(i=0;i<4;i++)
        {
            int xx=x+f[0][i];
            int yy=y+f[1][i];
            if(xx>=0&&xx<3&&yy>=0&&yy<3)
            {
                int add1=xx*3+yy;
                struct node next=now;
                next.add0=add1;
                next.s[now.add0]=next.s[add1];
                next.s[add1]=0;
                next.add0=add1;
                next.order=Contor(next.s,9);
                if(vis[next.order]==0)
                {
                    vis[next.order]=1;
                    next.road=now.road+fang[i];
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    char x;
    for(int i=0;i<9;i++)
    {
        cin>>x;
        if(x=='x')
        {
            start.s[i]=0;
            start.add0=i;
        }
        else
        start.s[i]=x-'0';
    }
    start.order=Contor(start.s,9);
    jiecheng[0]=1;
    for(int i=1;i<=9;i++)
    {
        jiecheng[i]=i*jiecheng[i-1];
    }
    bfs();
    if(flag)
    cout<<anss<<endl;
    else
    cout<<"unsolvable"<<endl;
 } 