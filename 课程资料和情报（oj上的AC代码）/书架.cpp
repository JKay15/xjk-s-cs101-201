#include <bits/stdc++.h>
using namespace std;
int N,B;
int main(){
    scanf("%d%d",&N,&B);
    vector<int> H(N);
    for(int i=0;i<N;i++)scanf("%d",&H[i]);
    sort(H.begin(),H.end(),greater<int>());
    vector<int> cum(N);
    partial_sum(H.begin(),H.end(),cum.begin());
    cout<<lower_bound(cum.begin(),cum.end(),B)-cum.begin()+1;
    return 0;
}