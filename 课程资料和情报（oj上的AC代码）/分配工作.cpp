//想法是对的，但是没写对
// #include <bits/stdc++.h>
// using namespace std;
// int n,k;
// vector<int> cont;
// bool vis[20];
// bool dfs(int m,int num,int cur,int tot){
//     if(tot==n)return 1;
//     if(num>k)return 0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]&&cur+cont[i]<=m){
//             vis[i]=1;
//             bool tmp=dfs(m,num,cur+cont[i],tot+1);
//             vis[i]=0;
//             if(tmp)return 1;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(!vis[i]&&cur+cont[i]>m){
//             vis[i]=1;
//             bool tmp=dfs(m,num+1,cont[i],tot+1);
//             vis[i]=0;
//             if(tmp)return 1;
//         }
//     }
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>k;
//     cont.resize(n);
//     for(int i=0;i<n;i++)cin>>cont[i];
//     sort(cont.begin(),cont.end(),greater<int>());
//     int r=accumulate(cont.begin(),cont.end(),0);
//     int l=cont[0];
//     int ans=r;
//     while(l<=r){
//         int m=(l+r)>>1;
//         for(int i=0;i<n;i++)vis[i]=0;
//         if(dfs(m,1,0,0)){
//             ans=m;
//             r=m-1;
//         }else l=m+1;
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& work, int k, int max_time) {
    vector<int> workers(k, 0);
    function<bool(int)> dfs = [&](int index) {
        if (index == work.size()) return true;
        for (int i = 0; i < k; ++i) {
            if (workers[i] + work[index] <= max_time) {
                workers[i] += work[index];
                if (dfs(index + 1)) return true;
                workers[i] -= work[index];
            }
            if (workers[i] == 0) break;
        }
        return false;
    };
    return dfs(0);
}
int min_max_work_time(int n, int k, vector<int>& times) {
    int left = *max_element(times.begin(), times.end());
    int right = accumulate(times.begin(), times.end(), 0);
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(times, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; ++i)cin >> times[i];
    int result = min_max_work_time(n, k, times);
    cout << result << "\n";
    return 0;
}