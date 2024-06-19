#include <bits/stdc++.h>
using namespace std;
int n;
int top,bot,l,r;
struct node{
    int x,y;
};
node p1,p2,p3;
void check(){
    if(p2.x>p1.x){
        if(p3.y>p2.y){
            top=min(top,p2.y);
            l=max(l,p2.x);
        }
    }else if(p2.x<p1.x){
        if(p3.y<p2.y){
            bot=max(bot,p2.y);
            r=min(r,p2.x);
        }
    }else if(p1.y>p2.y){
        if(p3.x>p2.x){
            top=min(top,p2.y);
            r=min(r,p2.x);
        }
    }else if(p1.y<p2.y){
        if(p3.x<p2.x){
            bot=max(bot,p2.y);
            l=max(l,p2.x);
        }
    }
}
bool ok(){
    //这里可以取等
    return(top>=bot&&r>=l);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
        top=r=numeric_limits<int>::max();
        bot=l=numeric_limits<int>::min();
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        node first=p1;
        node second=p2;
        for(int i=2;i<n;i++){
            cin>>p3.x>>p3.y;
            check();
            p1=p2;p2=p3;
        }
        //注意这里不要更新p1,p2了
        p3=first;
        check();
        p1=p2,p2=p3,p3=second;
        check();
        cout<<((ok())?"Yes":"No")<<"\n";
    }

}