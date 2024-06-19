#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n){
        vector<int> bat(n);
        for(int i=0;i<n;i++)cin>>bat[i];
        sort(bat.begin(),bat.end(),greater<int>());
        double total = 1.0*accumulate(bat.begin(),bat.end(),0);
        printf("%.1f\n",((bat[0]>1.0*total/2)?(total-bat[0]):(1.0*total/2)));
    }
    return 0;
}