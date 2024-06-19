#include <bits/stdc++.h>
using namespace std;
int player[10005],n,m,tmp;
struct node{
    int id,num;
    node(int x=0,int y=0):id(x),num(y){}
    bool operator<(const node&x)const{
        if(num==x.num)return id<x.id;
        return num>x.num;
    }
};
int main(){
    while(cin>>n>>m&&n){
        vector<node> ans;
        memset(player,0,sizeof(player));
        for(int i=0;i<n*m;i++){
            cin>>tmp;
            player[tmp]++;
        }
        for(int i=1;i<=10000;i++)if(player[i])ans.push_back({i,player[i]});
        sort(ans.begin(),ans.end());
        int cur=ans[1].num,pos=2;
        cout<<ans[1].id;
        while(ans[pos].num==cur)cout<<" "<<ans[pos++].id;
        cout<<"\n";
    }
    return 0;
}