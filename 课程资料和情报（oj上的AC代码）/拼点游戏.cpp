#include <bits/stdc++.h>
using namespace std;
int n;
int solve(vector<int>& C,vector<int>& S){
    int ans=-1;
    for(int i=n;i>=0;i--){
        int tag=1;
        int res=0;
        for(int k=0;k<i;k++){
            if(C[k]>S[n+k-i]){
                tag=0;
                break;
            }else res+=(C[k]==S[n+k-i])?2:3;
        }
        if(tag){
            if(res+n-i<ans)break;
            ans=res+n-i;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>n&&n){
        vector<int> C(n);
        vector<int> S(n);
        for(int i=0;i<n;i++)cin>>C[i];
        for(int i=0;i<n;i++)cin>>S[i];
        sort(C.begin(),C.end());
        sort(S.begin(),S.end());
        int ans=solve(C,S);
        int ans1=4*n-solve(S,C);
        cout<<ans<<" "<<ans1<<endl;
    }
    return 0;
}