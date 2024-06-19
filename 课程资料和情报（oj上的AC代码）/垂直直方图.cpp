#include <bits/stdc++.h>
using namespace std;
bool board[26][320];
int num[26],maxn;
int main(){
    for(int i=0;i<4;i++){
        string tmp;
        getline(cin,tmp);
        for(auto x:tmp)if(x>='A'&&x<='Z'){
            board[x-'A'][num[x-'A']++]=1;
            maxn=max(maxn,num[x-'A']);
        }
    }
    for(int i=maxn-1;i>=0;i--){
        for(int j=0;j<26;j++)
            if(!board[j][i])cout<<"  ";
            else cout<<"* ";
        cout<<"\n";
    }
    for(int i=0;i<26;i++)cout<<char('A'+i)<<" ";

    return 0;
}