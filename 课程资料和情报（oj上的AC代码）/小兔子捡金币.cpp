#include <bits/stdc++.h>
using namespace std;
int n,k,i,j,T,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>k>>n;
    while(k--){
        cin>>i>>j;
        x=min(i,min(j,min(n-i+1,n-j+1)));
        T=4*(n-x+1)*(x-1);
        if(i==x)cout<<j-x+T+1<<"\n";
        else if(j==x)cout<<T+3*(n-2*x+1)+n-x+1-i+1<<"\n";
        else if(n-i+1==x)cout<<T+2*(n-2*x+1)+n-x+1-j+1<<"\n";
        else cout<<T+(n-2*x+1)+i-x+1<<"\n";
    }
    return 0;
}
