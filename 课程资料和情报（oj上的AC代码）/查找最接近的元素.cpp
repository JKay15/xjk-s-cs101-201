#include <bits/stdc++.h>
using namespace std;
int n,m,tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> cont(n);
    for(int i=0;i<n;i++)cin>>cont[i];
    cin>>m;
    while(m--){
        cin>>tmp;
        auto ans=lower_bound(cont.begin(),cont.end(),tmp);
        if(ans==cont.end())cout<<cont[n-1]<<"\n";
        else if(ans==cont.begin()||((*ans-tmp)<(tmp-*(ans-1))))cout<<*ans<<"\n";
        else cout<<*(ans-1)<<"\n";
    }
    return 0;
}