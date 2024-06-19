#include <bits/stdc++.h>
using namespace std;
int n,m,i=1,j;
int main(){
    cin>>n>>m;
    int lim[4]={n,n,1,1};
    while(m){
        j++;
        if(m==1&&i==(n+1)/2){break;}
        for(;j<lim[0]&&m;j++){m--;if(!m)break;}
        for(;i<lim[1]&&m;i++){m--;if(!m)break;}
        for(;j>lim[2]&&m;j--){m--;if(!m)break;}
        for(;i>lim[3]&&m;i--){m--;if(!m)break;}
        if(m)i++;else break;
        for(int k=0;k<4;k++)lim[k]+=((k<2)?-1:1);
    }
    cout<<i<<" "<<j;
    return 0;
}