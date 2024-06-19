#include <bits/stdc++.h>
using namespace std;
#define check(x,y)(x>=0&&x<9&&y>=0&&y<8)
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
string ans;
unordered_map<int,int> tmp;
int dist(int cx,int cy,int mx,int my){
    if(cx==mx)return (cy>my? 3:4);
    if(cy==my)return (cx>mx? 1:6);
    if(cx<mx)return (cy>my? 5:7);
    return (cy>my? 0:2);
}
struct node{
    string path="";
    int x,y;
    char bd[9][8];
    vector<int> cont={};
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string now="LOSS\n";
        string now_path="";
        node root;
        for(int i=0;i<9;i++)
        for(int j=0;j<8;j++){
            cin>>root.bd[i][j];
            if(root.bd[i][j]=='S'){
                root.x=i;
                root.y=j;
            }else if(root.bd[i][j]=='E')root.cont.push_back(i*8+j);
        }
        queue<node> q;
        q.push(root);
        int num=q.size();
        while(num){
            if(now[0]=='W')break;
            while(num--){
                auto cur=q.front();
                q.pop();
                if(cur.cont.size()==0&&(now_path==""||now_path>cur.path)){
                    now="WIN "+to_string(cur.path.length()/2)+"\n";
                    now+=cur.path+"\n";
                    now_path=cur.path;
                }
                for(int i=0;i<8;i++){
                    int xx=cur.x+dx[i],yy=cur.y+dy[i];
                    if(check(xx,yy)&&cur.bd[xx][yy]=='.'){
                        tmp.clear();
                        node tbd;
                        for(int j=0;j<9;j++)for(int k=0;k<8;k++)tbd.bd[j][k]=cur.bd[j][k];
                        tbd.bd[cur.x][cur.y]='.';
                        tbd.bd[xx][yy]='S';
                        tbd.x=xx,tbd.y=yy;
                        tbd.path=cur.path+char('0'+1+i)+" ";
                        bool ok=1;
                        for(auto x:cur.cont){
                            int cx=x/8,cy=x%8;
                            tbd.bd[cx][cy]='.';
                            int dis=dist(cx,cy,xx,yy);
                            int cxx=cx+dx[dis],cyy=cy+dy[dis];
                            int ww=cxx*8+cyy;
                            if(tmp[ww])tmp[ww]+=1;
                            else if(cxx==xx&&cyy==yy){
                                ok=0;
                                break;
                            }else if(tbd.bd[cxx][cyy]!='#')tmp[ww]=1;
                        }
                        if(ok){
                            for(auto [a,b]:tmp){
                                int nx=a/8,ny=a%8;
                                if(b==1){
                                    tbd.cont.push_back(a);
                                    tbd.bd[nx][ny]='E';
                                }else tbd.bd[nx][ny]='#';
                            }
                            q.push(tbd);
                        }
                    }
                }
            }
            num=q.size();
        }
        ans+=now;
    }
    cout<<ans;
    return 0;
}