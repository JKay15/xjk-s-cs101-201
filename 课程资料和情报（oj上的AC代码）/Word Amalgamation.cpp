#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dic;
string tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>tmp&&tmp[0]!='X')dic.emplace(tmp);
    while(cin>>tmp&&tmp[0]!='X'){
        sort(tmp.begin(),tmp.end());
        bool ok=0;
        do{
            if(dic.find(tmp)!=dic.end()){
                ok=1;
                cout<<tmp<<"\n";
            }
        }while(next_permutation(tmp.begin(),tmp.end()));
        if(!ok)cout<<"NOT A VALID WORD\n";
        cout<<"******\n";
    }
    return 0;
}