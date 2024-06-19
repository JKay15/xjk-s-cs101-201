//有一个很坑的点在于给出的两个点不一定谁先谁后呢
#include <bits/stdc++.h>
using namespace std;
struct wall{
    int l,r;
    bool operator<(const wall&x)const{
        if(l==x.l)return r>x.r;
        return l<x.l;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,k,tmp;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<wall> a(n);
        vector<int> ok(n,0),wall(110,0);
        for(int i=0;i<n;i++){
            cin>>a[i].l>>tmp>>a[i].r>>tmp;
            if(a[i].l>a[i].r)swap(a[i].l, a[i].r);
            for(int j=a[i].l;j<=a[i].r;j++)wall[j]++;
        }
        int ans=0;
        sort(a.begin(),a.end());
        for(int i=0;i<105;i++){
            if(wall[i]>k){
                int tag=wall[i]-k;
                auto cmp=[&a](int &x,int &y){return a[x].r>a[y].r;};
                vector<int> x;
                for(int j=0;j<n;j++){
                    if(!ok[j]&&a[j].l<=i&&a[j].r>=i)x.push_back(j);
                    else if(a[j].l>i)break;
                }
                sort(x.begin(),x.end(),cmp);
                for(int i=0;i<tag;i++){
                    ok[x[i]]=1;
                    for(int j=i;j<=a[x[i]].r;j++)wall[j]--;
                }
                ans+=tag;
            }
        }
        cout<<ans<<"\n";
    }
}
// 非常暴力的思路，基本想法是，找到导致最多列大于k的墙，移除它，之后结算影响：重新计算有哪些列是大于k的，以及剩余的墙影响的列的数量——重新排序，继续之前的操作
// 缺点是计算非常慢
// 但是，找影响最多的墙，这个思路是非常正确的，只不过没必要做的那么极端
// 注意到，如果某一列超过了k，就必须要移走至少超过的数量的墙才行，那么移走哪些呢？
// 如果我们是从左往右考虑列的话，那么我们当然是考虑向右延伸得更远的墙移走才对，这样的话，这道题就做完了
//  #include <bits/stdc++.h>
//  using namespace std;
//  struct wall{
//      int l,r,num;
//      bool operator<(const wall&x)const{
//          return num>x.num;
//      }
//  };
//  int main(){
//      ios::sync_with_stdio(false);
//      cin.tie(nullptr);
//      int t,n,k;
//      cin>>t;
//      while(t--){
//          cin>>n>>k;
//          vector<wall> a(n);
//          int mmax=0;
//          for(int i=0;i<n;i++){
//              int tmp;
//              cin>>a[i].l>>tmp>>a[i].r>>tmp;
//              mmax=max(mmax,a[i].r);
//          }
//          vector<int> num(mmax+1);
//          for(int i=0;i<n;i++)
//          for(int j=a[i].l;j<=a[i].r;j++)num[j]++;
//          unordered_map<int,int> problem;
//          for(int i=0;i<mmax+1;i++)if(num[i]>k)problem.insert({i,num[i]-k});
//          for(int i=0;i<n;i++){
//              for(int j=a[i].l;j<=a[i].r;j++)if(num[j]>k)a[i].num++;
//          }
//          sort(a.begin(),a.end());
//          int ans=0;
//          while(problem.size()){
//              unordered_set<int> rem;
//              for(int i=a[0].l;i<=a[0].r;i++){
//                  if(problem.find(i)!=problem.end()){
//                      if(problem[i]==1){
//                          for(int j=1;j<n;j++){
//                              if(i>=a[j].l&&i<=a[j].r){
//                                  if(a[j].num==1)rem.insert(j);
//                                  else a[j].num--;
//                              }
//                          }
//                          problem.erase(i);
//                      }else problem[i]--;
//                  }
//              }
//              vector<wall> tmp;
//              for(int i=1;i<n;i++)if(rem.find(i)!=rem.end())tmp.push_back(a[i]);
//              a=tmp;
//              ans++;
//              sort(a.begin(),a.end());
//          }
//          cout<<ans<<"\n";
//      }

//     return 0;
// }