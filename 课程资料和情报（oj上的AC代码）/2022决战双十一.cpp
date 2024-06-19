//雷点：POJ不能用getchar()，要用cin.ignore()代替。。。
#include <bits/stdc++.h>
using namespace std;
int n,m,consum[6];
vector<pair<int,int>> price[9],store[6];
int dfs(int i){
    if(i>n){
        int total=0,t_d=0;
        for(int j=1;j<=m;j++){
            int dis=0;
            total+=consum[j];
            for(auto x:store[j])dis=max(dis,((consum[j]>=x.first)?x.second:0));
            t_d+=dis;
        }
        t_d+=(total/300)*50;
        return -t_d;
    }
    int ans=0x7777777;
    for(auto x:price[i]){
        consum[x.first]+=x.second;
        ans=min(ans,dfs(i+1)+x.second);
        consum[x.first]-=x.second;
    }
    return ans;
}
void input1(int t,int ok){
    for(int i=1;i<=t;i++){
        string tmp,part;
        getline(cin,tmp);
        istringstream iss(tmp);
        while(iss>>part){
            istringstream subiss(part);
            int key,value;char colon;
            subiss>>key>>colon>>value;
            if(ok)store[i].push_back({key,value});
            else price[i].push_back({key,value});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin.ignore();
    input1(n,0);input1(m,1);
    cout<<dfs(1);
    return 0;
}