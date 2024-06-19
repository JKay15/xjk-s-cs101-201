//优先队列的贪心，似乎是和什么单调栈有关，但是我这方面接触的不多，我写的来回遍历的贪心超时了

#include <bits/stdc++.h>
using namespace std;
struct cow
{
    int l,r,id;
    friend bool operator<(const cow&x,const cow&y){
        return x.r>y.r;
    }
};
bool cmp(const cow& x,const cow& y){
    if(x.l==y.l)return x.r<y.r;
    return x.l<y.l;
}
int n;
cow farm[50005];
int num[50005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>farm[i].l>>farm[i].r;
        farm[i].id=i;
    }
    sort(farm+1,farm+n+1,cmp);
    int total=1;
    cow root = farm[1];
    num[farm[1].id]=total;
    priority_queue<cow> q;
    q.push(root);
    for(int i=2;i<=n;i++){
        cow cur=q.top();
        if(cur.r<farm[i].l){
            num[farm[i].id]=num[cur.id];
            q.pop();
            q.push(farm[i]);
        }else{
            num[farm[i].id]=++total;
            q.push(farm[i]);
        }
    }
    cout<<total<<endl;
    for(int i=1;i<=n;i++){
        cout<<num[i]<<endl;
    }
    return 0;
}