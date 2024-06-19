//贪心差就差在没办法给出足够的信息，普通的从左往右的dp数组也没有足够的信息，这时候想到背包是很自然的，因为v\w这些的范围都不大，又能成为下标提供信息
//当然这题多维度的下标确实要好好想想怎么找
//以及不要从左往右推，这题的路径记录就是一个提示
//隐约感觉到了背包问题，但是没有想下去了
//后续知道是背包问题后，转化出来了正确的dp数组含义（其实空间压缩还是错的），但是又因为遍历顺序和空间压缩的冲突，不会递推了
//这道背包题大概是把要素拉满了，也说明了我们对于背包问题的理解还差一些
//还有这个路径记录写的很少，所以见到就慌了
#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int dp[25][805],road[25][805];
struct node{
    int s1,s2;
};
vector<node> s;
bool where(int i,int j,int k){
    if(i==0)return 0;
    if(road[i][j]==k)return 1;
    return where(i-1,j-s[road[i][j]].s1+s[road[i][j]].s2,k);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m&&n){
        cout<<"Jury #"<<++t<<"\n";
        s.clear();
        s.resize(n);
        for(int i=0;i<n;i++)cin>>s[i].s1>>s[i].s2;
        memset(dp,-1,sizeof(dp));
        memset(road,0,sizeof(road));
        int num=20*m;
        dp[0][20*m]=0;
        for(int i=1;i<=m;i++)
        for(int j=0;j<=2*num;j++){
            if(~dp[i-1][j]){
                for(int k=0;k<n;k++){
                    if(!where(i-1,j,k)){
                        if(dp[i][j+s[k].s1-s[k].s2]<dp[i-1][j]+s[k].s1+s[k].s2){
                            dp[i][j+s[k].s1-s[k].s2]=dp[i-1][j]+s[k].s1+s[k].s2;
                            road[i][j+s[k].s1-s[k].s2]=k;
                        }
                    }
                }
            }
        }
        int ans=0x7777777;
        for(int i=num;i<=2*num;i++)
        if(~dp[m][i]){
            ans=i-num;
            break;
        }
        for(int i=num-1;i>=0;i--){
            if((~dp[m][i])&&(num-i<ans||(num-i==ans&&dp[m][i]>dp[m][ans+num]))){
                ans=i-num;
                break;
            }
        }
        int sc1=(dp[m][ans+num]+ans)>>1,sc2=dp[m][ans+num]-sc1;
        cout<<"Best jury has value "<<sc1<<" for prosecution and value "<<sc2<<" for defence:\n";
        vector<int> ans1;
        int x=m,y=ans+num;
        while(x){
            ans1.push_back(road[x][y]);
            y-=(s[road[x][y]].s1-s[road[x][y]].s2);
            x--;
        }
        sort(ans1.begin(),ans1.end());
        for(auto x:ans1)cout<<" "<<x+1;
        cout<<"\n\n";
    }
    return 0;
}