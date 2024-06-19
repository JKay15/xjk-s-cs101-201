//很奇怪，没想到怎么优化，即使用筛，也会出现内存过大的问题，不知道咋搞
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int num;
    cin >> num;
    int p[10] = {11, 23, 29, 37, 41, 43, 47, 53, 59};
    for (int i = 0; i != 10 && p[i] < num; ++i) {
        long long result = static_cast<long long>(pow(2, p[i])) - 1;
        long long temp = result;
        long long factor = 2;

        bool flag = false;
        while (factor * factor < result) {
            if (result % factor == 0) {
                flag = true;
                result /= factor;
                cout << factor << " * ";
            } else {
                factor++;
            }
        }
        if (flag)
            cout << result << " = " << temp << " = ( 2 ^ " << p[i] << " ) - 1" << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59};
// void pro(ll x){
//     int first=0;
//     int lim=sqrt(x);
//     for(int i=2;i<lim;i++){
//         while(x%i==0&&x>1){
//             if(!first){
//                 first=1;
//                 cout<<i;
//             }else cout<<" * "<<i;
//             x/=i;
//         }
//     }
//     if(x!=1)cout<<" * "<<x;
// }
// int is_prime(ll x){
//     int lim=sqrt(x);
//     for(int i=2;i<lim;i++){
//         if(x%i==0)return 0;
//     }
//     return 1;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin>>n;
//     for(auto x:primes){
//         if(x>n)break;
//         else{
//             ll tmp=static_cast<long long>(pow(2, x)) - 1;;
//             if(!is_prime(tmp)){
//                 pro(tmp);
//                 cout<<" = "<<(1<<x)-1<<" = "<<"( 2 ^ "<<x<<" ) - 1\n";
//             }
//         }
//     }
//     return 0;
// }