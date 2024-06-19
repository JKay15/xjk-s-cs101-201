#include <bits/stdc++.h>
using namespace std;
#define gap 1e-10
#define f(x) (x*x*x-5*x*x+10*x-80)
int main(){
    double l=5.6,r=5.8;
    double ans=5;
    while(l+gap<=r){
        double mid = (l+r)/2;
        if(f(mid)<0)
            l=mid+gap;
        else{
            ans=mid;
            r=mid-gap;
        }
    }
    printf("%.9f",ans);
    return 0;
}