#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D;
    cin>>N>>D;
    vector<int> price[N];
    for(int i=0;i<N;i++){
        price[i].resize(D);
        for(int j=0;j<D;j++)cin>>price[i][j];
    }
    //这里不保证利润一定非负，所以这里千万不要初始化为0
    int ans=-0x7777777,a1=0,a2=0;
    for(int i=0;i<N-1;i++)
    for(int j=i+1;j<N;j++){
        int sum=0,sum2=0,profit=0;
        for(int k=0;k<3;k++){
            sum+=(price[i][k]-price[j][k]);
            sum2+=(price[i][k]-price[j][k])*(price[i][k]-price[j][k]);
        }
        for(int k=3;k<D-1;k++){
            int diff=price[i][k]-price[j][k];
            double mean=1.0*sum/k;
            double stdd=sqrt(1.0*sum2/k-mean*mean);
            int num=(diff-mean)/stdd;
            profit+=(-num*(price[i][k+1]-price[i][k])+num*(price[j][k+1]-price[j][k]));
            sum+=diff;
            sum2+=diff*diff;
        }
        if(profit>ans){
            ans=profit;
            a1=i;a2=j;
        }
    }
    cout<<a1+1<<" "<<a2+1<<" "<<ans;
    return 0;
}
