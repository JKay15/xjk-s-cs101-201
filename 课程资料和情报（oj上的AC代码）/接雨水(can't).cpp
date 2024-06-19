//又是单调栈，nmd
#include <bits/stdc++.h>
using namespace std;
int N;
int solve(vector<int>& height) {
    int ans = 0;
    stack<int> stk;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int top = stk.top();
            stk.pop();
            if (stk.empty()) {
                break;
            }
            int left = stk.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        stk.push(i);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    vector<int> h(N);
    for(int i=0;i<N;i++)cin>>h[i];
    cout<<solve(h);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> high;
// vector<int> diff;
// void det(vector<int> &h){
//     int tag =-1;
//     if(h[0]>h[1]){
//         high.push_back(0);
//         tag++;
//         diff.push_back(0);
//     }
//     for(int i=1;i<n-1;i++){
//         if((h[i]>h[i-1]&&h[i]>=h[i+1])||(h[i]>=h[i-1]&&h[i]>h[i+1])){
//             high.push_back(i);
//             tag++;
//             diff.push_back(0);
//         }else{
//             if(tag>=0)diff[tag]+=max(h[high[tag]]-h[i],0);
//         }
//     }
//     if(h[n-1]>h[n-2]){
//         high.push_back(n-1);
//         diff.push_back(0);
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n;
//     vector<int> h(n);
//     for(int i=0;i<n;i++)cin>>h[i];
//     det(h);
//     int l=high.size();
//     if(l==0)cout<<0<<"\n";
//     else{
//         int tag=0,ans=0;
//         for(int i=1;i<l;i++){
//             if(h[high[i]]>=h[high[tag]]){
//                 ans+=diff[tag];
//                 tag=i;
//             }else if(i==l-1){
//                 ans+=diff[tag]-(high[i]-high[tag]-1)*(h[high[tag]]-h[high[i]]);
//             }else{
//                 diff[tag]+=((h[high[tag]]-h[high[i]])*(high[i+1]-high[i])+diff[i]);
//             }
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }