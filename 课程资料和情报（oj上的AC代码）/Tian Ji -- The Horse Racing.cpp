//ans初始化的问题，不要忘了！
#include <bits/stdc++.h>
using namespace std;
int n;
int solve(vector<int>& C,vector<int>& S){
    int ans=-200*n;
    for(int i=n;i>=0;i--){
        int tag=1;
        int res=0;
        for(int k=0;k<i;k++){
            if(C[k]>S[n+k-i]){
                tag=0;
                break;
            }else res+=(C[k]==S[n+k-i])?0:200;
        }
        if(tag){
            if(res-200*(n-i)<ans)break;
            ans=res-200*(n-i);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n&&n){
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout<<solve(b,a)<<"\n";
    }
    return 0;
}