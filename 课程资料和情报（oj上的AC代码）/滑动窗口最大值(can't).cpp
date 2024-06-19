//q存下标就可以保证队列里面不会出现不在窗口中的元素
#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> q;
    cin>>n>>k;
    vector<int> nums(n),res;
    for(int i=0;i<n;i++)cin>>nums[i];
    for(int i=0;i<n;i++){
        if(!q.empty()&&q.front()==i-k)q.pop_front();
        while(!q.empty()&&nums[q.back()]<=nums[i])q.pop_back();
        q.push_back(i);
        if(i>=k-1)res.push_back(nums[q.front()]);
    }
    for_each(res.begin(),res.end(),[](int x){cout<<x<<" ";});
    return 0;
}