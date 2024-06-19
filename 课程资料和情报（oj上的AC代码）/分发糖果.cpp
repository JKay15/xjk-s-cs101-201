#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> ratings(n);
    vector<int> candy(n);
    for(int i=0;i<n;i++){
        cin>>ratings[i];
        candy[i]=1;
    }
    int total=n;
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            if(candy[i]<=candy[i-1]){
                total+=(candy[i-1]+1-candy[i]);
                candy[i]=candy[i-1]+1;
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            if(candy[i]<=candy[i+1]){
                total+=(candy[i+1]+1-candy[i]);
                candy[i]=candy[i+1]+1;
            }
        }
    }
    cout<<total;
    return 0;
}