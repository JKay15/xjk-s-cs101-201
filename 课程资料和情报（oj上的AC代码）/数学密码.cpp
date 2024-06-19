#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=6;i<=n;i++)if(!(n%i)){cout<<n/i;return 0;}
    return 0;
}