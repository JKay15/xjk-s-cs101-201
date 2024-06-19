#include <bits/stdc++.h>
using namespace std;
#define eps 1e-12
double f(double x){return 1.0*(x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121);} 
int main(){
    double l=1.5,r=2.4;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(f(mid)>0)l=mid;
        else r=mid;
    }
    printf("%.6f",l);
    return 0;
}