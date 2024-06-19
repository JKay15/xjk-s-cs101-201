//这是一道哈希的题目，我用对角线的性质混过去了
#include <bits/stdc++.h>
using namespace std;
int n;
vector<array<int,2>> po;
struct node{
    int lx,ly,id1,id2,l;
    node(){}
    bool operator<(const node&x)const{
        if(lx==x.lx){
            if(ly==x.ly)return l<x.l;
            return ly<x.ly;
        }
        return lx<x.lx;
    }
    bool chuizhi(node& x){
        int a1=po[id1][0]-po[id2][0],a2=po[id1][1]-po[id2][1];
        int b1=po[x.id1][0]-po[x.id2][0],b2=po[x.id1][1]-po[x.id2][1];
        return (a1*b1+a2*b2==0);
    }
}mid[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        po.resize(n);
        for(int i=0;i<n;i++)cin>>po[i][0]>>po[i][1];
        int num=0,cl=0,cr=0,ans=0;
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            mid[num].lx=po[i][0]+po[j][0];
            mid[num].ly=po[i][1]+po[j][1];
            mid[num].l=pow(po[i][0]-po[j][0],2)+pow(po[i][1]-po[j][1],2);
            mid[num].id1=i;mid[num++].id2=j;
        }
        sort(mid,mid+num);
        for(int i=0;i<num-1;i++){
            if(mid[i].lx==mid[i+1].lx&&mid[i].ly==mid[i+1].ly&&mid[i].l==mid[i+1].l)cr++;
            else{
                for(int j=cl;j<cr;j++)
                for(int p=j+1;p<=cr;p++)
                if(mid[j].chuizhi(mid[p]))ans++;
                cl=cr=i+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}