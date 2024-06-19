#include <bits/stdc++.h>
using namespace std;
#define out cout<<board[cx][cy]<<"\n"
int col,row,dir,board[105][105],cx=1,cy=0,tot=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>row>>col;
    for(int i=1;i<=row;i++)
    for(int j=1;j<=col;j++)cin>>board[i][j];
    int lim[4]={col,row,1,1};
    for(int i=1;i<=(min(col,row)+1)/2&&tot<col*row;i++){
        cy++;
        if(tot+1==col*row&&i==(min(col,row)+1)/2){out;}
        for(;cy<lim[0]&&tot<col*row;cy++){out;tot++;}
        for(;cx<lim[1]&&tot<col*row;cx++){out;tot++;}
        for(;cy>lim[2]&&tot<col*row;cy--){out;tot++;}
        for(;cx>lim[3]&&tot<col*row;cx--){out;tot++;}
        cx++;
        for(int j=0;j<4;j++)lim[j]+=((j<2)?-1:1);
    }
    return 0;
}