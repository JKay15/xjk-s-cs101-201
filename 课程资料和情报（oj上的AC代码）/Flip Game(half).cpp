#include <bits/stdc++.h>
using namespace std;
bool board[16];
int tag;
bool change(int bit){
    bool board1[16];
    for(int i=0;i<16;i++)board1[i]=board[i];
    for(int i=0;i<16;i++){
        if(bit&(1<<i)){
            board1[i]=!(board1[i]);
            if(i/4>0)board1[i-4]=!(board1[i-4]);
            if(i/4<3)board1[i+4]=!(board1[i+4]);
            if(i%4>0)board1[i-1]=!(board1[i-1]);
            if(i%4<3)board1[i+1]=!(board1[i+1]);
        }
    }
    for(int i=1;i<16;i++){
        if(board1[i]!=board1[i-1])return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<16;i++){
        char tmp;
        cin>>tmp;
        board[i]=((tmp=='w')?1:0);
    }
    int num=0x7777777;
    for(int i=0;i<(1<<16);i++){
        if(change(i)){
            int tmp=0;
            for(int j=0;j<16;j++){
                if(i&(1<<j))tmp++;
            }
            num=min(num,tmp);
        }
    }
    if(num==0x7777777)cout<<"Impossible\n";
    else cout<<num<<"\n";
    return 0;
}