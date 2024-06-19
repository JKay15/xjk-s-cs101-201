//cal的时候其实如果不拘泥于栈的形式的，完全可以从后往前算，就不会因为减号或者除号的问题而在处理阶段预先处理了，但是目前的应该也是对的
#include <bits/stdc++.h>
using namespace std;
string tmp;
int now;
double cal(stack<char>&ops,stack<double>&nums){
    while(!ops.empty()){
        double num1=nums.top();nums.pop();
        double num2=nums.top();nums.pop();
        if(ops.top()=='+')num1+=num2;
        else if(ops.top()=='-')num1=num2-num1;
        else if(ops.top()=='*')num1*=num2;
        else num1=1.0*num2/num1;
        nums.push(num1);
        ops.pop();
    }
    return nums.top();
}
double solve(int i,int l){
    stack<char> ops;
    stack<double> nums;
    int cur=0,update=0;
    for(int pos=i;pos<l;pos++){
        if(tmp[pos]>='0'&&tmp[pos]<='9'){
            cur=cur*10+tmp[pos]-'0';
            update=0;
        }else{
            if(!update){
                nums.push(cur);
                cur=0;
                update=1;
            }
            if(tmp[pos]=='+'||tmp[pos]=='-'){
                while(!ops.empty()&&(ops.top()=='*'||ops.top()=='/')){
                    double num1=nums.top();nums.pop();
                    double num2=nums.top();nums.pop();
                    nums.push((ops.top()=='*')?num1*num2:1.0*num2/num1);
                    ops.pop();
                }
                while(!ops.empty()&&(ops.top()=='-')){
                    double num1=nums.top();nums.pop();
                    double num2=nums.top();nums.pop();
                    nums.push(num2-num1);
                    ops.pop();
                }
                ops.push(tmp[pos]);
            }else if(tmp[pos]=='/'){
                ops.push(tmp[pos]);
            }else if(tmp[pos]=='*'){
                while(!ops.empty()&&(ops.top()=='/')){
                    double num1=nums.top();nums.pop();
                    double num2=nums.top();nums.pop();
                    nums.push(1.0*num2/num1);
                    ops.pop();
                }
                ops.push(tmp[pos]);
            }else if(tmp[pos]=='('){
                nums.push(solve(pos+1,l));
                pos=now;
            }else{
                now=pos;
                return cal(ops,nums);
            }
        }
    }
    if(!update)nums.push(cur);
    return cal(ops,nums);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>tmp){
        now=0;
        cout<<solve(0,tmp.length())<<"\n";
    }
}