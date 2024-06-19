#include <bits/stdc++.h>
using namespace std;
vector<int> mapp[4];
void rotate(int x){
    vector<int> tmp=mapp[x];
    for(int i=0;i<6;i++)mapp[x][(i+1)%6]=(tmp[i]+1)%6;
}
char findp(char x,int i,int r){
    if(r)for(int j=0;j<6;j++)if(mapp[i][j]==x-'a')return char(j+'a');
    return char(mapp[i][x-'a']+'a');
}
char rec(char x){
    return char(mapp[3][x-'a']+'a');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t1,t2;
    for(int i=0;i<3;i++){
        mapp[i].resize(6);
        for(int j=0;j<6;j++){
            cin>>t1>>t2;
            mapp[i][t1-1]=t2-1;
        }
    }
    mapp[3].resize(6);
    for(int i=0;i<3;i++){
        cin>>t1>>t2;
        mapp[3][t1-1]=t2-1;mapp[3][t2-1]=t1-1;
    }
    string tmp;
    cin>>tmp;
    int l=tmp.length();
    for(int i=0;i<l;i++){
        for(int j=0;j<3;j++)tmp[i]=findp(tmp[i],j,0);
        tmp[i]=rec(tmp[i]);
        for(int j=2;j>=0;j--)tmp[i]=findp(tmp[i],j,1);
        rotate(0);
        if((i+1)%6==0)rotate(1);
        if((i+1)%36==0)rotate(2);
    }
    cout<<tmp;
    return 0;
}