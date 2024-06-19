#include <bits/stdc++.h>
using namespace std;
int dp,dp1;
int main(){
    char x;
    scanf("%c",&x);
    dp=(x=='R')?0:1;
    dp1=(x=='B')?0:1;
    while(scanf("%c",&x)==1){
        if(x=='B')dp=min(dp,dp1)+1;
        else dp1=min(dp1,dp)+1;
    }
    cout<<dp;
    return 0;
}