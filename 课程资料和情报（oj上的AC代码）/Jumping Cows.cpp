#include <bits/stdc++.h>
using namespace std;
int n,total,t=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> potion(n+2);
    for(int i=1;i<=n;i++)cin>>potion[i];
    for(int i=1;i<=n;i++){
        if(potion[i]>=potion[i-1]&&potion[i]>potion[i+1]&&t%2)total+=potion[i],t++;
        else if(potion[i]<=potion[i-1]&&potion[i]<potion[i+1]&&!(t%2))total-=potion[i],t++;
    }
    cout<<total<<"\n";
    return 0;
}