//方法肯定是对了的，所有点也都过了，但是好像测评一个点都没给我跑就挂了
#include <bits/stdc++.h>
using namespace std;
int lis[100005],sta,cur,n,num;
struct cmp1{
    bool operator()(const int x,const int y){
        return lis[x]<lis[y];
    }
};
struct cmp2{
    bool operator()(const int x,const int y){
        return lis[x]>lis[y];
    }
};
priority_queue<int,vector<int>,cmp1> big;
priority_queue<int,vector<int>,cmp2> small;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    string tmp;
    cin>>tmp>>num;
    lis[cur++]=num;
    big.push(cur-1);
    for(int i=1;i<n;i++){
        cin>>tmp;
        if(tmp[0]=='a'){
            cin>>num;
            lis[cur++]=num;
            while(!small.empty()&&small.top()<sta){
                small.pop();
            }
            while(!big.empty()&&big.top()<sta){
                big.pop();
            }
            if(num<=lis[big.top()]){
                if((cur-1-sta)%2){
                    small.push(big.top());
                    big.pop();
                }
                big.push(cur-1);
            }else{
                small.push(cur-1);
                if(!((cur-1-sta)%2)){
                    big.push(small.top());
                    small.pop();
                } 
            }
        }else if(tmp[0]=='d'){
            sta++;
            if((cur+1-sta)%2&&lis[sta-1]>lis[big.top()]){
                small.push(big.top());
                big.pop();
            }
            if(!((cur+1-sta)%2)&&lis[sta-1]<=lis[big.top()]){
                big.push(small.top());
                small.pop();
            }
            while(!small.empty()&&small.top()<sta){
                small.pop();
            }
            while(!big.empty()&&big.top()<sta){
                big.pop();
            }
        }else{
            while(!small.empty()&&small.top()<sta){
                small.pop();
            }
            while(!big.empty()&&big.top()<sta){
                big.pop();
            }
            if((cur-sta)%2)cout<<lis[big.top()]<<"\n";
            else{
                double ans=1.0*(lis[big.top()]+lis[small.top()])/2;
                if(ans==(int)(lis[big.top()]+lis[small.top()])/2)cout<<ans<<"\n";
                else printf("%.1f\n",ans);
            }
        }
    }
    return 0;
}