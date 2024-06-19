//随着cur的改变，后续没用过的node的排序准则也需要改变，毕竟mmax和mmin的计算依赖于左边界，随着左边界在选择新的node后的改变，我们也应该重新给剩下的节点排序
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int x,y;
    int mmin,mmax;
};
bool cmp(const node&x,const node&y){
    if(x.mmin+x.y==y.mmin+y.y)return x.y<y.y;
    return x.mmin+x.y<y.mmin+y.y;
}
void change(vector<node>& lis,int zero,int start){
    for(int i=start;i<n;i++){
        lis[i].mmin=max(zero,lis[i].x+1-lis[i].y);
        lis[i].mmax=min(m-lis[i].y,lis[i].x);
    }
    sort(lis.begin()+start,lis.end(),cmp);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<node>lis(n);
    for(int i=0;i<n;i++){
        cin>>lis[i].x>>lis[i].y;
    }
    change(lis,0,0);
    int cur=0,total=0;
    for(int i=0;i<n;i++){
        if(lis[i].mmax>=cur){
            if(cur>=lis[i].mmin)cur+=lis[i].y;
            else cur=lis[i].mmin+lis[i].y;
            total++;
            change(lis,cur,i+1);
        }
    }
    cout<<total<<"\n";
    return 0;
}