#include <bits/stdc++.h>
using namespace std;
int x,y,z;
void change(int dir,int dis){    
    if(dir%3==0)x+=((dir<3)?dis:-dis);
    else if(dir%3==1)y+=((dir<3)?dis:-dis);
    else z+=((dir<3)?dis:-dis);
}
struct people{
    int f=0,b=3,l=4,r=1,u=2,d=5;
    void left(int x1){
        change(l,x1);
        int tmp=f;f=l;l=b;b=r;r=tmp;
    }
    void right(int x1){
        change(r,x1);
        int tmp=r;r=b;b=l;l=f;f=tmp;
    }
    void up(int x1){
        change(u,x1);
        int tmp=f;f=u;u=b;b=d;d=tmp;
    }
    void down(int x1){
        change(d,x1);
        int tmp=d;d=b;b=u;u=f;f=tmp;
    }
    void forward(int x1){change(f,x1);}
    void back(int x1){change(b,x1);swap(f,b);swap(l,r);}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n,x1;
    cin>>m;
    while(m--){
        x=y=z=0;people a;
        cin>>n;
        while(n--){
            string tmp;
            cin>>tmp>>x1;
            if(tmp[0]=='l')a.left(x1);
            else if(tmp[0]=='r')a.right(x1);
            else if(tmp[0]=='u')a.up(x1);
            else if(tmp[0]=='d')a.down(x1);
            else if(tmp[0]=='f')a.forward(x1);
            else a.back(x1);
        }
        cout<<x<<" "<<y<<" "<<z<<" "<<a.f<<"\n";
    }
    return 0;
}