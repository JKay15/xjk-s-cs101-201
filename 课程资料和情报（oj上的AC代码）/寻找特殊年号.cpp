#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int y;
    cin>>y;
    int bonus=1;
    while(true){
        int year=y+bonus;
        int sum=0;
        while(year){
            sum+=year%10;
            year/=10;
        }
        if(sum==20){
            cout<<y+bonus<<endl;
            break;
        }
        bonus++;
    }

    return 0;
}