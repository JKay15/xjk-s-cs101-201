#include <bits/stdc++.h>
using namespace std;
int x;
struct node{
    int v,id;
    node *lc=nullptr,*rc=nullptr,*fa;
    node(int x=0,int y=0,node* f=nullptr):v(x),id(y),fa(f){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x;
    node root{x};
    node& cur=root;
    while(cin>>x){
        //从下往上找对的位置
        while(cur.id){
            if((cur.id>0&&x<cur.v)||(cur.id<0&&x>cur.v))cur=*cur.fa;
            else break;
        }
        //如果要折返往下，和往上的逻辑是对称的
        if(cur.v>x){
            if(cur.lc==nullptr){
                cur.lc=&node{x,-1,&cur};
                cur=*cur.lc;
            }else{
                while(cur.lc!=nullptr&&x<cur.lc->v)cur=*cur.lc;
                if(x>cur.lc->v){
                    node *tmp=&cur;
                    cur.lc->fa=&node{x,-1,tmp};
                    tmp=cur.lc;
                    cur.lc=tmp->fa;
                    tmp->fa->lc=tmp;
                    cur=*tmp->fa;
                }else{
                    cur.lc->lc=&node{x,-1,cur.lc};
                    cur=*cur.lc->lc;
                }
            }
        }else{
            if(cur.rc==nullptr){
                cur.rc=&node{x,1,&cur};
                cur=*cur.rc;
            }else{
                while(cur.rc!=nullptr&&x>cur.lc->v)cur=*cur.rc;
                if(x<cur.rc->v){
                    node *tmp=&cur;
                    cur.rc->fa=&node{x,1,tmp};
                    tmp=cur.rc;
                    cur.rc=tmp->fa;
                    tmp->fa->rc=tmp;
                    cur=*tmp->fa;
                }else{
                    cur.rc->rc=&node{x,1,cur.rc};
                    cur=*cur.rc->rc;
                }
            }
        }
    }
    return 0;
}