//又是一道python题，c++提交非常别扭
#include <bits/stdc++.h>
using namespace std;
int m,n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},ans;
#define check(x,y) (x>=0&&x<m&&y>=0&&y<n)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    vector<int> pos[m],grade(m*n);
    vector<string> score(m*n);
    for(int i=0;i<m;i++){
        pos[i].resize(n);
        for(int j=0;j<n;j++)cin>>pos[i][j];
    }
    cin.ignore();
    string tmp;
    for(int i=0;i<m*n;i++){
        getline(cin,tmp);
        score[i]=tmp;
        istringstream iss(tmp);
        int t;
        grade[i]=0;
        while(iss>>t)grade[i]+=t;
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        int tag=0;
        for(int k=0;k<4;k++){
            int xx=i+dx[k],yy=j+dy[k];
            if(check(xx,yy)&&score[pos[xx][yy]]==score[pos[i][j]]){
                tag=1;
                break;
            }
        }
        ans+=tag;
    }
    int pre=0,lim=m*n*0.4;
    sort(grade.begin(),grade.end(),greater<int>());
    for(auto x:grade)pre+=(x>grade[lim])?1:0;
    cout<<ans<<" "<<pre;
    return 0;
}