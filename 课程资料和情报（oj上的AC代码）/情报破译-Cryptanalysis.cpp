#include <bits/stdc++.h>
using namespace std;
#define check(x) ((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
string code;
void made(string&cur,int& cnt,int i){
    reverse(cur.begin(),cur.end());
    for(auto& x:cur){
        if(x<'a')x=char((x-'A'+26-cnt)%26+'A');
        else x=char((x-'a'+26-cnt)%26+'a');
    }
    int ll=cur.length();
    for(int j=i-ll;j<i;j++)code[j]=cur[j-i+ll];
    cur="";cnt++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(getline(cin,code)){
        string cur="";
        int cnt=1,l=code.length();
        for(int i=0;i<l;i++){
            if(check(code[i]))cur+=code[i];
            else if(cur!="")made(cur,cnt,i);
        }
        if(cur!="")made(cur,cnt,l);
        cout<<code<<"\n";
    }
    return 0;
}