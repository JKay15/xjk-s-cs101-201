#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp;
    int ok=1,l;
    while(getline(cin,tmp)){
        l=tmp.length();
        if(ok){
            for(int i=0;i<l;i++){
                if(tmp[i]!='\"'&&tmp[i]!='/')cout<<tmp[i];
                else if(tmp[i]=='\"'){
                    int j=l-1;
                    for(;j>i;j--)if(tmp[j]=='\"')break;
                    for(;i<=j;i++)cout<<tmp[i];
                    i--;
                }else if(i<l-1&&tmp[i]=='/'&&tmp[i+1]=='*'){
                    ok=0;
                    i+=2;
                    while(i<l-1&&(!(tmp[i]=='*'&&tmp[i+1]=='/')))i++;
                    if((++i)<l)ok=1;
                }else cout<<tmp[i];
            }
            if(ok)cout<<"\n";
        }else if(l>1&&tmp[l-1]=='/'&&tmp[l-2]=='*'){ok=1;cout<<"\n";}
    }
    return 0;
}