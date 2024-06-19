#include <bits/stdc++.h>
using namespace std;
int where=0;
void fill1(int cur,map<string,int>& tmp,string& name,map<string,int>& dict){
    cur=(cur==0)?1:cur;
    if(name!="")dict[name]+=(cur==0)?1:cur;
    else if(tmp.size()) for(auto x:tmp)dict[x.first]+=(cur==0)?x.second:cur*x.second;
    tmp.clear();
    name="";
}
map<string,int> dfs(int i,int l,string &f){
    map<string,int> dict;
    map<string,int> tmp;
    string name="";
    int cur=0;
    for(int pos=i;pos<l;pos++){
        if(f[pos]>='a'&&f[pos]<='z')name+=f[pos];
        else if(f[pos]>='A'&&f[pos]<='Z'){
            fill1(cur,tmp,name,dict);
            cur=0;
            name+=f[pos];
        }else if(f[pos]>='0'&&f[pos]<='9')cur=cur*10+f[pos]-'0';
        else if(f[pos]=='('){
            fill1(cur,tmp,name,dict);
            tmp=dfs(pos+1,l,f);
            for(auto x:tmp)x.second*=((cur==0)?1:cur);
            cur=0;
            pos=where;
        }else{
            fill1(cur,tmp,name,dict);
            where=pos;
            return dict;
        }
    }
    fill1(cur,tmp,name,dict);
    return dict;
}   
string countOfAtoms(string formula) {
    map<string,int> dict=dfs(0,formula.length(),formula);
    string ans="";
    for(auto x:dict){
        ans+=x.first;
        if(x.second!=1)ans+=to_string(x.second);
    }
    return ans;
}   
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp;
    cin>>tmp;
    cout<<countOfAtoms(tmp)<<"\n";
    return 0;
}