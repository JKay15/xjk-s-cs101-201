#include <bits/stdc++.h>
using namespace std;
string tmp1,tmp2,ans;
unordered_map<char,int> dict2;
struct node{
    char x;
    node* left,*right;
    node(char X=' '):x(X){left=nullptr;right=nullptr;}
};
//建树使用指针，不要用对象，因为对象会被销毁，但是指针new出来之后除非delete，否则不会被销毁
node *build(int l1,int r1,int l2,int r2,string& tmp1,string& tmp2){
    if(l1>r1)return nullptr;
    node * head=new node(tmp1[l1]);
    if(l1==r1)return head;
    int k=dict2[head->x];
    //关键是要理解处理二叉树是不得不使用递归的，但现在往往会害怕递归，这很不好
    //这里的数学关系很重要，理解到前中序遍历的左右子树在哪里
    head->left=build(l1+1,l1+k-l2,l2,k-1,tmp1,tmp2);
    head->right=build(l1+k-l2+1,r1,k+1,r2,tmp1,tmp2);
    return head;
}
void suf(node* head){
    if(head->left!=nullptr)suf(head->left);
    if(head->right!=nullptr)suf(head->right);
    ans+=head->x;
}
int main(){
    while(cin>>tmp1>>tmp2){
        dict2.clear();
        int l1=tmp1.length(),l2=tmp2.length();
        for(int i=0;i<=l2;i++)dict2[tmp2[i]]=i;
        ans="";
        node* root=build(0,l1-1,0,l2-1,tmp1,tmp2);
        suf(root);
        cout<<ans<<"\n";
    }
    return 0;
}