//别忘了二分的范围，是i后面所有数，而不是所有数，这样可能出现num[i]+num[i]=m的情况
#include <bits/stdc++.h>
using namespace std;
int n,m;
int solve(vector<int> &num){
    if(num[n-1]+num[n-2]<m)return -1;
    for(int i=0;i<n;i++){
        int tmp=m-num[i];
        auto x=lower_bound(num.begin()+i+1,num.end(),tmp);
        if(x!=num.end()&&*x==tmp)return num[i];
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    cin>>m;
    sort(num.begin(),num.end());
    int ans=solve(num);
    if(ans!=-1)
        cout<<ans<<" "<<m-ans;
    else cout<<"No";
    return 0;
}