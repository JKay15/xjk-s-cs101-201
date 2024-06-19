#include <bits/stdc++.h>
using namespace std;
int n,k,t1,t2;
unordered_set<int> fir;
struct cow{
    int id,a,b;
    cow(){}
    cow(int x,int y,int z):id(x),a(y),b(z){}
};
bool cmp1(cow&x,cow&y){
    return x.a>y.a;
}
bool cmp2(cow&x,cow&y){
    return x.b>y.b;
}
int main(){
    scanf("%d%d",&n,&k);
    vector<cow> q(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t1,&t2);
        q[i].id=i;q[i].a=t1;q[i].b=t2;
    }
    sort(q.begin()+1,q.end(),cmp1);
    for(int i=1;i<=k;i++)fir.insert(q[i].id);
    sort(q.begin()+1,q.end(),cmp2);
    int cur=1;
    while(fir.find(q[cur].id)==fir.end())cur++;
    printf("%d",q[cur].id);
    return 0;
}