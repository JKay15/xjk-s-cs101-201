#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> tmp={{"zero","one","two","three","four","five","six","seven","eight","nine"},{"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"},{"hundred"},{"thousand"},{"million"}};
vector<string> cont;
unordered_map<string,int> dict;
string t;
int dfs(int i,int start,int end){
    if(i<0||start>end)return 0;
    auto pos=find(cont.begin()+start,cont.begin()+end+1,tmp[i][0]);
    string tar=tmp[i][0];
    if(pos==cont.begin()+end+1){
        int l=tmp[i].size();
        for(int j=1;j<l;j++){
            pos=find(cont.begin()+start,cont.begin()+end+1,tmp[i][j]);
            if(pos!=cont.begin()+end+1){
                tar=tmp[i][j];
                break;
            }
        }
    }
    if(pos==cont.begin()+end+1)return dfs(i-1,start,end);
    int ans=dict[tar];
    int p1=dfs(i-1,start,pos-cont.begin()-1);
    int p2=dfs(i-1,pos-cont.begin()+1,end);
    return ((p1)?p1:1)*ans+p2;
}
int main(){
    for(int i=0;i<10;i++)dict.insert({tmp[0][i],i});
    for(int i=10;i<=20;i++)dict.insert({tmp[1][i-10],i});
    for(int i=30;i<100;i+=10)dict.insert({tmp[1][10+(i-20)/10],i});
    dict.insert({tmp[2][0],100});dict.insert({tmp[3][0],1000});dict.insert({tmp[4][0],1000000});
    string tmp;
    while(getline(cin,tmp)&&tmp!=""){
        cont.clear();
        istringstream iss(tmp);
        while(iss>>t)cont.push_back(t);
        int len=cont.size();
        if(cont[0]=="negative")cout<<-dfs(4,1,len-1)<<"\n";
        else cout<<dfs(4,0,len-1)<<"\n";
    }
    return 0;
}