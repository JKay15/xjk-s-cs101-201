// 思路对了，但是这种单调队列的还是写的不够熟练，所以WA了
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y;
    bool operator<(const node a) const
    {
        return x < a.x;
    }
} island[1000];

int main(void)
{
    int n, i, count, cid = 0;
    double tx, lx, rx, llx, rrx, d;
    while (scanf("%d%lf", &n, &d), n)
    {
        for (i = 0; i < n; i++)
            scanf("%d%d", &island[i].x, &island[i].y);
        sort(island, island + n);
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (island[i].y > d || island[i].y < 0)
            {
                count = -1;
                break;
            }
            if (i == 0)
            {
                count = 1;
                tx = sqrt(d * d - island[i].y * island[i].y);
                lx = island[i].x - tx;
                rx = island[i].x + tx;
            }
            else
            {
                tx = sqrt(d * d - island[i].y * island[i].y);
                llx = island[i].x - tx;
                rrx = island[i].x + tx;
                if (llx <= rx && rrx >= lx)
                {
                    lx = (lx < llx) ? llx : lx;
                    rx = (rx > rrx) ? rrx : rx;
                }
                else
                {
                    count++;
                    lx = llx;
                    rx = rrx;
                }
            }
        }
        printf("Case %d: %d\n", ++cid, count);
    }
}
// using namespace std;
// int n,d;
// struct node{
//     int x,y;
//     node(){}
//     node(int a,int b):x(a),y(b){}
//     friend bool operator<(const node&x,const node&y){
//         return x.x<y.x;
//     }
// };
// bool cmp(pair<double,double>& x,pair<double,double>& y){
//     if(x.first==y.first)return x.second<y.second;
//     return x.first<y.first;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int cas=0;
//     while(cin>>n>>d&&n){
//         cas++;
//         vector<node> island(n);
//         for(int i=0;i<n;i++)cin>>island[i].x>>island[i].y;
//         if(any_of(island.begin(),island.end(),[](node&x){return x.y>d;})){
//             cout<<"Case "<<cas<<": "<<-1<<"\n";
//         }else{
//             vector<pair<double,double> > _range(n);
//             for(int i=0;i<n;i++){
//                 _range[i].first=1.0*island[i].x-sqrt(1.0*d*d-1.0*island[i].y*island[i].y);
//                 _range[i].second=1.0*island[i].x+sqrt(1.0*d*d-1.0*island[i].y*island[i].y);
//             }
//             sort(_range.begin(),_range.end(),cmp);
//             int left=0,total=0;
//             while(left<n){
//                 total++;
//                 double cur=_range[left].second;
//                 int tag=0;
//                 for(int i=left+1;i<n;i++){
//                     if(_range[i].first<=cur){
//                         if(i<n-1)continue;
//                         else left=n;
//                     }else{
//                         left=i;
//                         tag=1;
//                         break;
//                     }
//                 }
//                 if(!tag)break;
//             }
//             cout<<"Case "<<cas<<": "
//             <<total<<endl;
//         }
//     }
//     return 0;
// }