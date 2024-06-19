//最小生成树的K算法，学习一下——只要能形成权值最小且不成环n-1条边就行，用并查集看新加的边是否会成环
//还有一种Prim算法，之后学习一下
#include <bits/stdc++.h>
using namespace std;
const int maxn=400;
int father[30],n;
struct node{
    int x,y,len;
    bool operator<(const node&x)const{
        return len<x.len;
    }
}edges[maxn];
void build(){
    for(int i=1;i<=n;i++)father[i]=i;
}
int find(int i){
    if(i!=father[i])father[i]=find(father[i]);
    return father[i];
}
bool union1(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return false;
    else father[fx]=fy;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        build();
        char tmp;
        int tmp1;
        int total=0;
        for(int i=1;i<n;i++){
            cin>>tmp>>tmp1;
            for(int i=0;i<tmp1;i++){
                char tmp2;
                int len;
                cin>>tmp2>>len;
                edges[total].x=tmp-'A'+1;
                edges[total].y=tmp2-'A'+1;
                edges[total++].len=len;
            }
        }
        sort(edges,edges+total);
        int ans=0;
        for(int i=0;i<total;i++)if(union1(edges[i].x,edges[i].y))ans+=edges[i].len; 
        cout<<ans<<"\n";
    }
    return 0;
}