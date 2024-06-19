#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int num[55],ori[55],n;
int dfs(int end){
    if(num[end]==ori[end])return 0;
    int mul=end-num[end],start=num[end];
    for(int i=start;i<end;i++)swap(ori[i],ori[i+1]);
    for(int i=start+1;i<end;i++)if(ori[i]!=num[i])return 0;
    if(!start)return 1;

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){cin>>num[i];ori[i]=i;}
    cout<<dfs(n-1);
    return 0;
}
// from itertools import accumulate
// mod = 1000000007
// N = int(input())
// p = list(map(int,input().split()))
// out = 0
// is_right = [False]*N
// impossible = False
// for i in range(N-1):
//     if p[i] == i:
//         impossible = True
//         break
//     if p[i] < i:
//         is_right[p[i]] = True
//     if i >= out:
//         if p[i] <= i:
//             impossible = True
//             break
//         else:
//             out = p[i]
//     elif i < out:
//         if p[i] > i:
//             impossible = True
//             break
// is_right[p[N-1]] = True

// if impossible:
//     print(0)
// else:
//     dp = [1]
//     for j in range(1,N-1):
//         if is_right[j]:
//             dp = list(reversed([0]+list(accumulate(reversed(dp)))))
//         else:
//             dp = [0]+list(accumulate(dp))
//     print(sum(dp)%mod)