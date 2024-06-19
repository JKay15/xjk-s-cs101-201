#include <bits/stdc++.h>
using namespace std;
struct Node{
    int exp;  //指数
    int coef; //系数
    struct Node *next=nullptr;
};
typedef Node* Poly;
Poly add(const Poly & A,const Poly & B){
    map<int,int,greater<int>> a;
    Poly cur=A->next;
    while(cur!=nullptr){
        a[cur->exp]+=cur->coef;
        cur=cur->next;
    }
    cur=B->next;
    while(cur!=nullptr){
        a[cur->exp]+=cur->coef;
        cur=cur->next;
    }
    Poly h=new Node;
    cur=h;
    for(auto [x,y]:a){
        cur->next=new Node;
        cur=cur->next;
        cur->coef=y,cur->exp=x;
    }
    return h;
}
Poly mul(const Poly & A,const Poly & B){
    map<int,int,greater<int>> a;
    Poly cur=A->next;
    while(cur!=nullptr){
        Poly cur1=B->next;
        while(cur1!=nullptr){
            a[cur->exp+cur1->exp]+=(cur1->coef*cur->coef);
            cur1=cur1->next;
        }
        cur=cur->next;
    }
    Poly h=new Node;
    cur=h;
    for(auto [x,y]:a){
        cur->next=new Node;
        cur=cur->next;
        cur->coef=y,cur->exp=x;
    }
    return h;
}   
void printPolynomial(const Poly &A){
    Poly cur=A->next;
    int first=1;
    while(cur!=nullptr){
        if(!cur->coef){
            cur=cur->next;
            continue;
        }
        if(cur->coef<0){
            first=0;
            if(cur->exp){
                if(cur->coef==-1){
                    if(cur->exp!=1)cout<<"-"<<"x^"<<cur->exp;
                    else cout<<"-"<<"x";
                }
                else{
                    if(cur->exp!=1)cout<<cur->coef<<"x^"<<cur->exp;
                    else cout<<cur->coef<<"x";
                } 
            }else cout<<cur->coef;
        }else{
            if(first){
                first=0;
                if(cur->exp){
                    if(cur->coef==1){
                        if(cur->exp!=1)cout<<"x^"<<cur->exp;
                        else cout<<"x";
                    }
                    else{
                        if(cur->exp!=1)cout<<cur->coef<<"x^"<<cur->exp;
                        else cout<<cur->coef<<"x";
                    }
                }else cout<<cur->coef;
            }else{
                if(cur->exp){
                    if(cur->coef==1){
                        if(cur->exp!=1)cout<<"+"<<"x^"<<cur->exp;
                        else cout<<"+"<<"x";
                    }
                    else{
                        if(cur->exp!=1)cout<<"+"<<cur->coef<<"x^"<<cur->exp;
                        else cout<<"+"<<cur->coef<<"x";
                    }
                }else cout<<"+"<<cur->coef;
            }
        }
        cur=cur->next;
    }
    cout<<"\n";
}
int t1,t2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Poly h1=new Node,h2=new Node;
    Poly cur1=h1,cur2=h2;
    while(cin>>t1>>t2&&(t1!=0||t2!=0)){
        cur1->next=new Node;
        cur1=cur1->next;
        cur1->coef=t1,cur1->exp=t2;
    }
    while(cin>>t1>>t2&&(t1!=0||t2!=0)){
        cur2->next=new Node;
        cur2=cur2->next;
        cur2->coef=t1,cur2->exp=t2;
    }
    Poly ans=add(h1,h2);
    printPolynomial(ans);
    ans=mul(h1,h2);
    printPolynomial(ans);
    return 0;
}