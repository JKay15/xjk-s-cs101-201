#include <bits/stdc++.h>
using namespace std;
int mat[41][41],n,tot,curx,cury;
int main(){
    cin>>n;
    n=2*n-1;
    cury=n/2;
    mat[0][cury]=++tot;
    while(tot<n*n){
        if(curx==0&&cury==n-1)curx=1;
        else if(curx>0&&cury<n-1&&mat[curx-1][cury+1])curx++;
        else{
            curx=(curx+n-1)%n;
            cury=(cury+1)%n;
        }
        mat[curx][cury]=++tot;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}