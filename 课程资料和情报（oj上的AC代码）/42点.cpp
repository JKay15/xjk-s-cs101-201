#include <bits/stdc++.h>
using namespace std;
#define eps 1e-5
int n;
bool dfs(vector<double> & num){
    int l=num.size();
    if(l==1&&fabs(num[0]-42)<eps)return 1;
    if(l==1&&fabs(num[0]-42)>=eps)return 0;
    vector<double> cont={};
    for(int i=0;i<l-1;i++){
        double tmp=num[i]+num[i+1];
        cont.push_back(tmp);
        for(int j=i+2;j<l;j++)cont.push_back(num[j]);
        if(dfs(cont))return 1;
        for(int j=i+1;j<l;j++)cont.pop_back();
        tmp=num[i]-num[i+1];
        cont.push_back(tmp);
        for(int j=i+2;j<l;j++)cont.push_back(num[j]);
        if(dfs(cont))return 1;
        for(int j=i+1;j<l;j++)cont.pop_back();
        tmp=num[i]*num[i+1];
        cont.push_back(tmp);
        for(int j=i+2;j<l;j++)cont.push_back(num[j]);
        if(dfs(cont))return 1;
        for(int j=i+1;j<l;j++)cont.pop_back();
        if(num[i+1]){
            tmp=1.0*num[i]/num[i+1];
            cont.push_back(tmp);
            for(int j=i+2;j<l;j++)cont.push_back(num[j]);
            if(dfs(cont))return 1;
            for(int j=i+1;j<l;j++)cont.pop_back();
        }
        cont.push_back(num[i]);
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<double> num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num.begin(),num.end());
    int tag=dfs(num);
    while(!tag&&next_permutation(num.begin(),num.end())){
        tag=dfs(num);
    }
    cout<<((tag)?"YES":"NO")<<"\n";
    return 0;
}