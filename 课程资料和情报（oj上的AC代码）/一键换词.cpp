//c++写着确实不舒服
#include <bits/stdc++.h>
using namespace std;
string lower(string x){
    for(auto&y:x)y=tolower(y);
    return x;
}
string art,t1[3],t2[3],puc[3]={" ",",","."};
int main(){
    getline(cin,art);
    cin>>t1[0]>>t2[0];
    art=" "+lower(art)+" ";
    for(int i=2;i>=0;i--){
        t1[i]=" "+lower(t1[0])+puc[i];
        t2[i]=" "+lower(t2[0])+puc[i];
    }
    int l=t1[0].length(),tag=0;
    auto pos=art.find(t1[0]);
    if(pos==string::npos){
        pos=art.find(t1[1]);
        tag=1;
    }
    if(pos==string::npos){
        tag=2;
        pos=art.find(t1[2]);
    }
    while(pos!=string::npos){
        art=art.substr(0,pos)+t2[tag]+art.substr(pos+l,art.length()-pos-l+1);
        for(int i=0;i<3;i++){
            pos=art.find(t1[i]);
            tag=i;
            if(pos!=string::npos)break;
        }
    }
    tag=1;
    art=art.substr(1,art.length()-2);
    for(auto& x:art){
        if(tag&&(x>='a'&&x<='z')){
            x=char(x-'a'+'A');
            tag=0;
        }else if(x=='.')tag=1;
    }
    cout<<art;
    return 0;
}