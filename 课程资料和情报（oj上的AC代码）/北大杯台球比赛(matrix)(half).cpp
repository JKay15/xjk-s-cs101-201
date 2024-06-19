//搞错了反弹的意思了，不是dx，dy都反向，这属于是物理没学好了。。。
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dict={{0,0},{8,0},{16,0},{0,5},{8,5},{16,5}};
int main(){
int x0,y0,x1,y1,dx,dy,f;
    cin>>x0>>y0>>x1>>y1>>dx>>dy>>f;
    int color=-1,tag=0;
    while(f--){
        x0+=dx;y0+=dy;
        if(x0==x1&&y0==y1)color*=-1;
        if(x0==0||x0==16)dx*=-1;
        else if(y0==0||y0==5)dy*=-1;
        for(auto x:dict){
            if(x.first==x0&&x.second==y0){
                cout<<color;
                tag=1;
                break;
            }
        }
        if(tag)break;
    }
    if(!tag)cout<<0;
    return 0;
}

