#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<string> cont(n);
    for(int i=0;i<n;i++)cin>>cont[i];
    sort(cont.begin(),cont.end());
    string t1=cont[n/2-1],t2=cont[n/2],tmp;
    int l=t1.length(),tag=0;
    for(int i=0;i<=l;i++){
        tmp=t1.substr(0,i);
        for(int j=0;j<26;j++){
            string tmp1=tmp+char('A'+j);
            if(tmp1>=t1&&tmp1<t2){
                tmp=tmp1;
                tag=1;
                break;
            }
        }
        if(tag)break;
    }
    cout<<tmp;
    return 0;
}