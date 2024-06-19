#include <bits/stdc++.h>
using namespace std;
string tar,art;
int num,init=-1;
int main(){
    cin>>tar;
    for(char& x:tar)x=tolower(x);
    cin.ignore();
    getline(cin,art);
    for(char& x:art)x=tolower(x);
    tar=" "+tar+" ";
    art=" "+art+" ";
    auto pos=art.find(tar);
    while(pos!=string::npos){
        if(init==-1)init=pos;
        num++;
        pos=art.find(tar,pos+1);
    }
    if(init==-1)cout<<init;
    else cout<<num<<" "<<init;
}