#include<bits/stdc++.h>
using namespace std;
string tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>tmp&&tmp!="."){
        int l=tmp.length();
        for(int i=1;i<=l;i++){
            if(l%i)continue;
            else{
                int r=i;
                for(;r<l;r++)if(tmp[r]!=tmp[r%i])break;
                if(r==l){
                    cout<<l/i<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}