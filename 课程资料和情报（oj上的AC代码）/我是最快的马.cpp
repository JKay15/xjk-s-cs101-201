//(1)没搞清楚憋马脚的含义（2）xx和yy是终点的话，不能标记vis
#include <bits/stdc++.h>
using namespace std;
int sx,sy,ex,ey,dx[8]={-1,1,-1,1,2,2,-2,-2},dy[8]={-2,-2,2,2,-1,1,-1,1},m,ok,num;
int ddx[8]={0,0,0,0,1,1,-1,-1},ddy[8]={-1,-1,1,1,0,0,0,0};
string anss;
set<pair<int,int>> dict,vis;
struct node{
    int x,y;
    string ans;
    node(){}
    node(int a,int b):x(a),y(b){
        ans="("+to_string(a)+","+to_string(b)+")";
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>sx>>sy>>ex>>ey>>m;
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        dict.insert({t1,t2});
        vis.insert({t1,t2});
    }
    queue<node> q;
    q.push({sx,sy});
    while(!ok){
        int ssize=q.size();
        for(int ii=0;ii<ssize;ii++){
            node cur=q.front();
            if(cur.x==ex&&cur.y==ey){ok=1;anss=cur.ans;num++;}
            q.pop();
            for(int i=0;i<8;i++){
                int xx=cur.x+dx[i],yy=cur.y+dy[i];
                int xx1=cur.x+ddx[i],yy1=cur.y+ddy[i];
                if(vis.find({xx,yy})==vis.end()&&dict.find({xx1,yy1})==dict.end()){
                    if(xx!=ex||yy!=ey)vis.insert({xx,yy});
                    node tmp;
                    tmp.x=xx;tmp.y=yy;
                    tmp.ans=cur.ans+"-"+"("+to_string(xx)+","+to_string(yy)+")";
                    q.push(tmp);
                }
            }
        }
    }
    if(num==1)cout<<anss;
    else cout<<num;
    return 0;
}