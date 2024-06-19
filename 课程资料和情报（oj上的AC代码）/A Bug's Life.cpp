#include <bits/stdc++.h>
using namespace std;
int t,m,n,t1,t2,set1[2005],a[2005];
int Find_set1(int x)
{
    if(x==set1[x])return x;
    int t=Find_set1(set1[x]);
    a[x]=(a[set1[x]] + a[x]) % 2;
    return set1[x]=t;
}
void Union(int x,int y)
{
    int fx=Find_set1(x);
    int fy=Find_set1(y);
    set1[fx]=fy;
    if(a[y]==0)a[fx]=1-a[x];
    else a[fx]=a[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for(int tag=1;tag<=t;tag++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)set1[i]=i,a[i]=0;
        int res=1;
        cout<<"Scenario #"<<tag<<":\n";
        while(m--){
            cin>>t1>>t2;
            int w1=Find_set1(t1),w2=Find_set1(t2);
            if(w1==w2&&a[t1]==a[t2])res=0;
            else Union(t1,t2);
        }
        if(res)cout<<"No suspicious bugs found!\n\n";
        else cout<<"Suspicious bugs found!\n\n";
    }
    return 0;
}