//没有考虑到不需要一直在一张最长的板子上切，完全可以切成两块之后，分别切，这样直接贪心就不行了
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n;
//     vector<int> sticks(n);
//     for(int i=0;i<n;i++)cin>>sticks[i];
//     sort(sticks.begin(),sticks.end(),greater<int>());
//     ll ans=accumulate(sticks.begin(),sticks.end(),0);
//     ll res=ans;
//     for(int i=0;i<n-2;i++){
//         res-=sticks[i];
//         ans+=res;
//     }
//     cout<<ans;
//     return 0;
// }
//倒着思考要怎么切，从最后两块板子开始找
//每次会被切的是最短的两个板子
//这两个板子就应该求和后放回队列，表示切之前的状态
//最后队列会变成一块板子
//又是优先队列的贪心。。。
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > q;
    int n,m,i,t;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>m,q.push(m);
    long long sum=0;
    while(q.size()>1)
    {
        m=q.top();
        q.pop();
        t=q.top();
        q.pop();
        sum+=(m+t);
        q.push(m+t);
    }
    cout<<sum<<endl;
    return 0;
}