//不知道为什么会错。。。
// #include <bits/stdc++.h>
// using namespace std;
// int n,m;
// int get_digit(int x){
//     for(int i=10;i>0;i--){
//         if(x&(1<<i))return i;
//     }
//     return 0;
// }
// int main(){
//     cin>>n>>m;
//     int i=get_digit(n)-1,j=get_digit(m)-1,ans=1;
//     while(i>=0&&j>=0){
//         int tmp1=n&(1<<i),tmp2=m&(1<<j);
//         if((tmp1)==(tmp2)){
//             ans=ans*2+(tmp1>>i);
//             i--,j--;
//         }else break;
//     }
//     cout<<ans;
//     return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
int solve(int x, int y);
int main()
{
    int x, y;
    cin >> x >> y;
    cout << solve(x, y);
    return 0;
}
int solve(int x, int y)
{
    if (x == y) return x;
    return solve(min(x, y), max(x, y) / 2);
}
