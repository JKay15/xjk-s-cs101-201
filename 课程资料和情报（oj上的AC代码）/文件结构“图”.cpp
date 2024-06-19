#include <bits/stdc++.h>
using namespace std;
int tag=1;
void print(int i,string name){
    for(int k=0;k<i;k++)cout<<"|     ";
    cout<<name<<"\n";
}
bool dfs(int i,string name){
    string tmp;
    cin>>tmp;
    if(tmp=="#")return 0;
    if(i==0)cout<<"DATA SET "<<tag++<<":\n";
    print(i,name);
    vector<string> files;
    do{
        if((!i&&tmp=="*")||(i&&tmp=="]"))break;
        if(tmp[0]=='d')dfs(i+1,tmp);
        else files.push_back(tmp);
    }while(cin>>tmp);
    sort(files.begin(),files.end());
    for(auto x:files)print(i,x);
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(1){
        if(!dfs(0,"ROOT"))break;
        cout<<"\n";
    }
    return 0;
}