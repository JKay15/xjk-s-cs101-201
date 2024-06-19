#include <bits/stdc++.h>
using namespace std;
int t,m,n,k,t1;
struct node{
    int x,y,num;
    node(){}
    node(int a,int b,int c):x(a),y(b),num(c){}
    bool operator<(const node&a)const{
        return num>a.num;
    }
};
vector<node> cont;
inline int dis(int i){
    if(i==-1)return cont[0].x;
    return abs(cont[i].x-cont[i+1].x)+abs(cont[i].y-cont[i+1].y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>m>>n>>k;
        cont.clear();
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            cin>>t1;
            cont.push_back({i,j,t1});
        }
        sort(cont.begin(),cont.end());
        int tot=0,cur_pos=-1,num=0;
        while(1){
            if(cur_pos>0&&!cont[cur_pos].num)break;
            if(tot+dis(cur_pos)+1+cont[cur_pos+1].x>k)break;
            else{
                tot+=dis(cur_pos++)+1;
                num+=cont[cur_pos].num;
            }
        }
        cout<<num<<"\n";
    }
    return 0;
}