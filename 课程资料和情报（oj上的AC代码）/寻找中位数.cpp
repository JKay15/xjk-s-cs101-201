#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    vector<int> ans(n);
    for(int i=0;i<n;i++)scanf("%d",&ans[i]);
    sort(ans.begin(),ans.end());
    printf("%d",ans[n/2]);
    return 0;
}