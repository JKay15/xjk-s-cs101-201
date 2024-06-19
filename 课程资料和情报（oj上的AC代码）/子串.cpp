#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string tmp1,tmp2;
    while(cin>>tmp1>>tmp2){
        int cur=-1,tag=1;
        for(auto x:tmp1){
            cur=tmp2.find(x,cur+1);
            if(cur==-1){
                tag=0;
                break;
            }
        }
        cout<<((tag)?"Yes":"No")<<"\n";
    }
    return 0;
}