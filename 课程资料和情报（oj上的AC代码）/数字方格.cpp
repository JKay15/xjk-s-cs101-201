#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int mmax=0;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            for(int c=1;c<=n;c++){
                if(!((a+b)%2)&&!((b+c)%3)&&!((a+b+c)%5)){
                    mmax=max(mmax,a+b+c);
                }
            }
        }
    }
    cout<<mmax<<endl;
    return 0;
}