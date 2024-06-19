//错误的
// #include <bits/stdc++.h>
// using namespace std;
// string tmp;
// int now,t;
// double cal(stack<char>&ops,stack<double>&nums){
//     while(!ops.empty()){
//         double num1=nums.top();nums.pop();
//         double num2=nums.top();nums.pop();
//         if(ops.top()=='+')num1+=num2;
//         else if(ops.top()=='-')num1=num2-num1;
//         else if(ops.top()=='*')num1*=num2;
//         else num1=int(num2/num1);
//         nums.push(num1);
//         ops.pop();
//     }
//     return nums.top();
// }
// double solve(int i,int l){
//     stack<char> ops;
//     stack<double> nums;
//     int cur=0,update=0;
//     for(int pos=i;pos<l;pos++){
//         if(tmp[pos]>='0'&&tmp[pos]<='9'){
//             cur=cur*10+tmp[pos]-'0';
//             update=0;
//         }else{
//             if(!update){
//                 nums.push(cur);
//                 cur=0;
//                 update=1;
//             }
//             if(tmp[pos]=='+'||tmp[pos]=='-'){
//                 while(!ops.empty()&&(ops.top()=='*'||ops.top()=='/')){
//                     double num1=nums.top();nums.pop();
//                     double num2=nums.top();nums.pop();
//                     nums.push((ops.top()=='*')?num1*num2:int(num2/num1));
//                     ops.pop();
//                 }
//                 while(!ops.empty()&&(ops.top()=='-')){
//                     double num1=nums.top();nums.pop();
//                     double num2=nums.top();nums.pop();
//                     nums.push(num2-num1);
//                     ops.pop();
//                 }
//                 ops.push(tmp[pos]);
//             }else if(tmp[pos]=='/'){
//                 while(!ops.empty()&&(ops.top()=='*')){
//                     double num1=nums.top();nums.pop();
//                     double num2=nums.top();nums.pop();
//                     nums.push(num2*num1);
//                     ops.pop();
//                 }
//                 ops.push(tmp[pos]);
//             }else if(tmp[pos]=='*'){
//                 while(!ops.empty()&&(ops.top()=='/')){
//                     double num1=nums.top();nums.pop();
//                     double num2=nums.top();nums.pop();
//                     nums.push(int(num2/num1));
//                     ops.pop();
//                 }
//                 ops.push(tmp[pos]);
//             }else if(tmp[pos]=='('){
//                 nums.push(solve(pos+1,l));
//                 pos=now;
//             }else{
//                 now=pos;
//                 return cal(ops,nums);
//             }
//         }
//     }
//     if(!update)nums.push(cur);
//     return cal(ops,nums);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>t;
//     while(t--){
//         cin>>tmp;
//         now=0;
//         cout<<int(solve(0,tmp.length()))<<"\n";
//     }
// }
#include<iostream>
#include<cstring>
using namespace std;
char exp[650];
char op[650];
int num[650];
int eptr, optr, nptr;
void process(char op) {
    int num2 = num[nptr --];
    int num1 = num[nptr];
    int res;
    switch(op) {
        case '+':res = num1 + num2; break;
        case '-':res = num1 - num2; break;
        case '*':res = num1 * num2; break;
        case '/':res = num1 / num2; break;
        default:res = 0;
    }
    num[nptr] = res;
}
int main() {
    int N; cin >> N;
    while (N --) {
        scanf("%s", exp);
        eptr =  optr = 0;
        nptr = -1;
        op[optr] = '(';
        int length = strlen(exp);
        exp[length] = ')';
        exp[length + 1] = '\0';
        while (exp[eptr] != '\0') {
            if (exp[eptr] >= '0' && exp[eptr] <= '9') {
                int cnum = atoi(exp + eptr);
                num[++ nptr] = cnum;
                while (eptr <= length && exp[eptr] >= '0' && exp[eptr] <= '9') eptr ++;
            }
            else {
                switch (exp[eptr]) {
                    case '(': {
                        op[++ optr] = '(';
                        break;
                    }
                    case ')': {
                        while (op[optr] != '(') {
                            process(op[optr]);
                            optr --;
                        }
                        optr --;
                        break;
                    }
                    case '-':;
                    case '+': {
                        if (op[optr] != '(') {
                            process(op[optr]);
                            optr --;
                            eptr --;//为了循环，将所有运算级别比'+'小的都算了。注意左边的'+''—'一定大于右边的
                        }
                        else
                            op[++ optr] = exp[eptr];
                        break;
                    }
                    case '/':;
                    case '*': {
                        if (op[optr] == '*' || op[optr] == '/') {
                            process(op[optr]);
                            optr --;
                            eptr --;
                        }
                        else
                            op[++ optr] = exp[eptr];
                        break;
                    }
                    default:break;
                }
                eptr ++;
            }
        }
        cout << num[0] << endl;
    }
}