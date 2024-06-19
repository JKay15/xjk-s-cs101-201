#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<int> cont;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cont.resize(n);
    for(int i=0;i<n;i++)cin>>cont[i];
    string tmp;
    cin>>tmp;
    sort(cont.begin(),cont.end());
    cin>>n;
    while(n--){
        cin>>q;
        cout<<cont[q-1]<<"\n";
    }
    return 0;
}