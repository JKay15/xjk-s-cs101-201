#include <bits/stdc++.h>
using namespace std;
unordered_map<char,char> mmap;
map<string,int> num;
int n;
string tmp;
void init(){
    int cur=6;
    for(int i=0;i<25;i++){
        if(char('A'+i)=='Q')continue;
        mmap.insert({char('A'+i),char('0'+(cur++)/3)});
    }
}
void change(string x){
    string cur="";
    for(auto y:x){
        if(y=='-')continue;
        if(y>='0'&&y<='9')cur+=y;
        else cur+=mmap[y];
    }
    cur=cur.substr(0,3)+"-"+cur.substr(3,4);
    num[cur]++;
}
int main(){
    ios::sync_with_stdio(false);
    init();
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        change(tmp);
    }
    int ok=1;
    for(auto x:num)
    if(x.second>1){
        ok=0;
        cout<<x.first<<" "<<x.second<<"\n";
    }
    if(ok)cout<<"No duplicates.";
    return 0;
}