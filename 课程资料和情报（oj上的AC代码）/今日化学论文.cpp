#include <bits/stdc++.h>
using namespace std;
string tmp;
int where,l;
string dfs(int x){
    string ans="";
    int times=0;
    for(int i=x;i<l;i++){
        if(tmp[i]=='['){
            string cur=dfs(i+1);
            i=where;
            ans+=cur;
        }else if(tmp[i]>='0'&&tmp[i]<='9')times=times*10+(tmp[i]-'0');
        else if(tmp[i]==']'){
            where=i;
            break;
        }else ans+=tmp[i];
    }
    string t=ans;
    for(int i=1;i<times;i++)ans+=t;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>tmp;
    l=tmp.length();
    cout<<dfs(0);
    return 0;
}