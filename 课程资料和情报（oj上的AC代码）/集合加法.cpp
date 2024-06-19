#include <bits/stdc++.h>
using namespace std;
int a,s,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>s>>a;
        vector<int> num1(a);
        for(int i=0;i<a;i++)cin>>num1[i];
        cin>>b;
        vector<int> num2(b);
        for(int i=0;i<b;i++)cin>>num2[i];
        sort(num1.begin(),num1.end(),greater<int>());
        sort(num2.begin(),num2.end());
        auto cur=num2.begin();
        int ans=0;
        for(int i=0;i<a;i++){
            cur=lower_bound(cur,num2.end(),s-num1[i]);
            auto pos=upper_bound(cur,num2.end(),s-num1[i]);
            if(*cur==s-num1[i]){
                ans+=pos-cur;
            }
            else if(cur==num2.end())break;
        }
        cout<<ans<<"\n";
    }

    return 0;
}