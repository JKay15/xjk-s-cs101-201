#include <bits/stdc++.h>
using namespace std;
double poland(){
    string tmp;
    cin>>tmp;
    if(tmp=="*")return poland()*poland();
    else if(tmp=="+")return poland()+poland();
    else if(tmp=="-")return poland()-poland();
    else if(tmp=="/")return 1.0*poland()/poland();
    else return stof(tmp);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    printf("%f\n",poland());
    return 0;
}