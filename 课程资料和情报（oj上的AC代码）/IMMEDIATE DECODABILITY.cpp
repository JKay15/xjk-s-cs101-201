//构建树的题目还是没有一个很好的模版，导致写的很繁琐，debug效率也很低
#include <bits/stdc++.h>
using namespace std;
string tmp;
bool ok=1,first=1;
struct node{
    bitset<1> code;
    node *left=nullptr,*right=nullptr;
    node(int x=0):code(x){}
    ~node(){
        if(left){
            left->~node();
            delete left;
        }
        if(right){
            right->~node();
            delete right;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=0;
    node root;
    while(cin>>tmp){
        if(tmp=="9"){
            root.left=root.right=nullptr;
            cout<<"Set "<<(++t)<<" is"<<((ok)?" ":" not ")<<"immediately decodable\n";
            first=ok=1;
        }else if(ok){
            node* cur=&root;
            bool tag=0;
            for(auto x:tmp){
            if(x=='0'){
            if(cur->left)cur=cur->left;
            else{
                if(cur->right||cur==&root||first){
                    cur->left=new node();
                    cur=cur->left;
                    first=1;
                    tag=1;
                }else{
                    tag=0;
                    break;
                }
                }
            }else{
            if(cur->right)cur=cur->right;
            else{
                if(cur->left||cur==&root||first){
                    cur->right=new node(1);
                    cur=cur->right;
                    first=1;
                    tag=1;
                }else{
                    tag=0;
                    break;
                }
            }
            }
            }
            first=0;
            if(!tag)ok=0;
        }
    }
    return 0;
}