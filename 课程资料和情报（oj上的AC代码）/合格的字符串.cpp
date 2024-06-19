#include <bits/stdc++.h>
using namespace std;
#define check(x)((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9'))
int n,where,l;
string tmp;
map<int,unordered_set<char>> dict;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<string> cont(n);
    for(int i=0;i<n;i++)cin>>cont[i];
    cin>>tmp;
    l=tmp.length();
    for(int i=0;i<l;i++){
        if(check(tmp[i])){
            dict[where]={tmp[i]};
            where++;
        }
        else{
            i++;
            while(tmp[i]!=']')dict[where].insert(tmp[i++]);
            where++;
        }
    }
    for(int i=0;i<n;i++){
        int ll=cont[i].length();
        if(ll!=where)continue;
        int ok=0;
        for(int j=0;j<where;j++){
            if(dict[j].find(cont[i][j])==dict[j].end()){
                if(cont[i][j]>='0'&&cont[i][j]<='9'){ok=1;break;}
                else if(cont[i][j]>='A'&&cont[i][j]<='Z'){
                    if(dict[j].find(char(cont[i][j]+'a'-'A'))==dict[j].end()){ok=1;break;}
                }else{
                    if(dict[j].find(char(cont[i][j]-'a'+'A'))==dict[j].end()){ok=1;break;}
                }
            }
        }
        if(!ok)cout<<i+1<<" "<<cont[i]<<"\n";
    }
    return 0;
}