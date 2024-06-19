#include <bits/stdc++.h>
using namespace std;
string name[3];
int n;
void solve(int n,int cur,int tar){
    if(n==1){
        cout<<1<<":"<<name[cur]<<"->"<<name[tar]<<endl;
        return ;
    }
    int new_tar = 0;
    for(;new_tar<3;new_tar++)
        if(new_tar!=cur&&new_tar!=tar)
            break;
    solve(n-1,cur,new_tar);
    cout<<n<<":"<<name[cur]<<"->"<<name[tar]<<endl;
    solve(n-1,new_tar,tar);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>name[0]>>name[1]>>name[2];
    solve(n,0,2);
    return 0;
}