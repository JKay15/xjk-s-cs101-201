#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,step;
    node(int a,int b,int c):x(a),y(b),step(c){}
};
set<pair<int,int>> dict;
int n,ans=-1;
void pushh(int xx,int yy,queue<node>& q,node& cur){
    if(dict.find({xx,yy})==dict.end()){
        dict.insert({xx,yy});dict.insert({yy,xx});
        q.push({xx,yy,cur.step+1});
    }
}
int main(){
    cin>>n;
    queue<node> q;
    q.push({1,0,0});
    while(!q.empty()){
        node cur=q.front();
        if(cur.x==n||cur.y==n){ans=cur.step;break;}
        q.pop();
        int xx=cur.x*2,yy=cur.y;
        pushh(xx,yy,q,cur);
        xx=cur.x,yy=cur.x*2;
        pushh(xx,yy,q,cur);
        xx=cur.x,yy=cur.y*2;
        pushh(xx,yy,q,cur);
        xx=cur.y*2,yy=cur.y;
        pushh(xx,yy,q,cur);
        xx=cur.x-cur.y,yy=cur.y;
        pushh(xx,yy,q,cur);
        yy=cur.x-cur.y,xx=cur.x;
        pushh(xx,yy,q,cur);
        yy=cur.y-cur.x,xx=cur.x;
        pushh(xx,yy,q,cur);
        xx=cur.y-cur.x,yy=cur.y;
        pushh(xx,yy,q,cur);
        xx=cur.x+cur.y,yy=cur.y;
        pushh(xx,yy,q,cur);
        xx=cur.x,yy=cur.x+cur.y;
        pushh(xx,yy,q,cur);
    }
    cout<<ans;
    return 0;
}