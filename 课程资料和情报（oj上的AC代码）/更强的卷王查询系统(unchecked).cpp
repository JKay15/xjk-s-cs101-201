#include <bits/stdc++.h>
using namespace std;
int n,m,tmp;
unordered_map<string, unordered_map<string,int> > lis;
bool cmp(const pair<string,double> &x,const pair<string,double> &y){
    if(x.second==y.second)return x.first<y.first;
    return x.second>y.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    string tmp1,tmp2;
    for(int i=1;i<=n;i++){
        cin>>tmp1>>tmp2>>tmp;
        lis[tmp2][tmp1]=tmp;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>tmp;
        vector<string> course(tmp);
        for(int i=0;i<tmp;i++)cin>>course[i];
        vector<pair<string,double> > sele;
        for(auto [name,cla]:lis){
            int tag=0,total=0;;
            for(auto x:course){
                if(cla.find(x)==cla.end()){
                    tag=1;
                    break;
                }else total+=cla[x];
            }
            if(!tag){
                sele.push_back({name,1.0*total/tmp});
            }
        }
        sort(sele.begin(),sele.end(),cmp);
        cout<<sele[0].first<<"\n";
    }  
    return 0;
}