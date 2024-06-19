#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
int R[maxn],H[maxn],minv[maxn],mins[maxn];
int N,M,ans=0x7777777;
void dfs(int i,int v,int s){
    if(s+mins[i]>ans)return ;
    if(v+minv[i]>N)return ;
    if(s+2*(N-v)/R[i+1]>=ans)return ;
    if(!i){
        if(v==N)ans=s;
        return ;
    }
    for(int r=min(R[i+1]-1,int(sqrt(N-v)));r>=i;r--){
        for(int h=min(H[i+1]-1,(N-v)/r/r);h>=i;h--){
            int tmp=((i==M)?r*r:0);
            H[i]=h,R[i]=r;
            dfs(i-1,v+r*r*h,s+2*r*h+tmp);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=1;i<=M;i++)
	{
		minv[i]=minv[i-1]+i*i*i;
		mins[i]=mins[i-1]+2*i*i;
	}
    R[M+1]=H[M+1]=0x7777777;
    dfs(M,0,0);
    cout<<((ans==0x7777777)?0:ans);
    return 0;
}