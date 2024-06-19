#include <bits/stdc++.h>
using namespace std;
int main(){
    string tmp;
    cin>>tmp;
    sort(tmp.begin(),tmp.end());
    do{cout<<tmp<<"\n";}
    while(next_permutation(tmp.begin(),tmp.end()));
    return 0;
}