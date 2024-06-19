#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double t,m=numeric_limits<double>::max(),ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        m=min(m,t);
        ans=max(ans,100.0*t/m);
    }
    printf("%.2f",ans);
    return 0;
}