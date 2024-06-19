// 思路：
// 每种操作最多进行3次，对应0 1 2 3次四种情况
// 解法一：
// 如果把所有情况都枚举出来，那么要枚举4^9=262144种，情况并不是非常庞大，可以用递归来减少代码量，最后对结果进行比较，输出最小的即可
// 解法二：
// 相当于对解法一的优化，先枚举前三种操作的所有情况，总共4^3=64种，然后确定后面六种操作的次数。因为第i种操作在i-9操作中都独占一种影响的时钟，比如操作4在4-9操作中独占A时钟，操作5在操作5-9中独占B时钟，只要前一种确定了，后一种就能根据所独占的时钟来确定操作次数。

#include <bits/stdc++.h>
#define mem(a,n) memset(a,n,sizeof(a))
typedef unsigned long long ull;
using namespace std;

//用于改变时钟的状态,index为操作编号,n为操作次数
void turn(int clk2[],int index,int n)
{
    switch(index)
    {
    case 1://ABDE
        clk2[1]=(clk2[1]+n)%4;
        clk2[2]=(clk2[2]+n)%4;
        clk2[4]=(clk2[4]+n)%4;
        clk2[5]=(clk2[5]+n)%4;
        break;
    case 2://ABC
        clk2[1]=(clk2[1]+n)%4;
        clk2[2]=(clk2[2]+n)%4;
        clk2[3]=(clk2[3]+n)%4;
        break;
    case 3://BCEF
        clk2[2]=(clk2[2]+n)%4;
        clk2[3]=(clk2[3]+n)%4;
        clk2[5]=(clk2[5]+n)%4;
        clk2[6]=(clk2[6]+n)%4;
        break;
    case 4://ADG
        clk2[1]=(clk2[1]+n)%4;
        clk2[4]=(clk2[4]+n)%4;
        clk2[7]=(clk2[7]+n)%4;
        break;
    case 5://BDEFH
        clk2[2]=(clk2[2]+n)%4;
        clk2[4]=(clk2[4]+n)%4;
        clk2[5]=(clk2[5]+n)%4;
        clk2[6]=(clk2[6]+n)%4;
        clk2[8]=(clk2[8]+n)%4;
        break;
    case 6://CFI
        clk2[3]=(clk2[3]+n)%4;
        clk2[6]=(clk2[6]+n)%4;
        clk2[9]=(clk2[9]+n)%4;
        break;
    case 7://DEGH
        clk2[4]=(clk2[4]+n)%4;
        clk2[5]=(clk2[5]+n)%4;
        clk2[7]=(clk2[7]+n)%4;
        clk2[8]=(clk2[8]+n)%4;
        break;
    case 8://GHI
        clk2[7]=(clk2[7]+n)%4;
        clk2[8]=(clk2[8]+n)%4;
        clk2[9]=(clk2[9]+n)%4;
        break;
    case 9://EFHI
        clk2[5]=(clk2[5]+n)%4;
        clk2[6]=(clk2[6]+n)%4;
        clk2[8]=(clk2[8]+n)%4;
        clk2[9]=(clk2[9]+n)%4;
        break;
    }
}
//判断时钟最终状态是否符合
bool judge(int clk2[])
{
    for(int i=1;i<10;i++)
    {
        if(clk2[i]) return 0;
    }
    return 1;
}
//打印结果
void print_res(int res[])
{
    for(int i=1;i<10;i++)
        for(int j=0;j<res[i];j++)
            cout<<i<<" ";
}
//获取总操作的次数
int get_len(int ans[])
{
    int len=0;
    for(int i=1;i<10;i++)
    {
        len+=ans[i];
    }
    return len;
}
//比较两个操作的大小
//方法：从前往后比较各个操作的次数
//若有一种操作次数不同，那么操作次数少的那种答案更小
//调用该函数的前提是两种答案的总次数一样
bool compare(int a[],int b[])
{
    for(int i=1;i<10;i++)
    {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 0;
}
int main()
{
    int clk1[10],clk2[10],ans[10],result[10],len=100;
    for(int i=1;i<10;i++) cin>>clk1[i];
    for(ans[1]=0;ans[1]<4;++ans[1])
    {
        for(ans[2]=0;ans[2]<4;++ans[2])
        {
            for(ans[3]=0;ans[3]<4;++ans[3])
            {
                memcpy(clk2,clk1,sizeof(clk1));
                turn(clk2,1,ans[1]);
                turn(clk2,2,ans[2]);
                turn(clk2,3,ans[3]);
                ans[4]=(4-clk2[1])%4;turn(clk2,4,ans[4]);
                ans[5]=(4-clk2[2])%4;turn(clk2,5,ans[5]);
                ans[6]=(4-clk2[3])%4;turn(clk2,6,ans[6]);
                ans[7]=(4-clk2[4])%4;turn(clk2,7,ans[7]);
                ans[8]=(4-clk2[7])%4;turn(clk2,8,ans[8]);
                ans[9]=(4-clk2[5])%4;turn(clk2,9,ans[9]);
                if(judge(clk2))
                {
                    int temp_len=get_len(ans);
                    //比较大小的方法：
                    //1.若长度比原答案长，肯定大于原答案
                    //2.若长度和原答案一样，调用函数进行比较
                    //3.若长度比原答案小，则替换为原答案
                    if(temp_len<len||(temp_len==len&&compare(ans,result)))
                    {
                        len=temp_len;
                        memcpy(result,ans,sizeof(ans));
                    }
                }
            }
        }
    }
    print_res(result);
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// bitset<262145> vis;
// vector<int> ops[10];
// string tmp[9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
// void init(){
//     for(int i=0;i<9;i++){
//         for(auto x:tmp[i]){
//             ops[i+1].push_back(x-'A');
//         }
//     }
// }
// int encode(vector<int>&x){
//     int ans=0,mul=1;
//     for(int i=0;i<9;i++){
//         ans+=x[i]*mul;
//         mul*=4;
//     }
//     return ans;
// }
// vector<int> decode(int x){
//     vector<int> aa;
//     int mul=4;
//     while(x){
//         aa.push_back((x%mul)/(mul/4));
//         x-=x%mul;
//         mul*=4;
//     }
//     return aa;
// }
// int operate(int rev,int i,int code){
//     vector<int> cl=decode(code);
//     if(rev)for(auto x:ops[i]) cl[x]=(cl[x]+3)%4;
//     else for(auto x:ops[i]) cl[x]=(cl[x]+1)%4;
//     return encode(cl);
// }
// struct node{
//     vector<int> ope;
//     int code;
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     init();
//     vector<int> rr;
//     for(int i=0;i<9;i++){
//         int tt;
//         cin>>tt;
//         rr.push_back(tt);
//     }
//     node root;
//     root.code=encode(rr);
//     rr=decode(root.code);
//     vis[root.code]=1;    
//     queue<node> q;
//     q.push(root);
//     int suc=0;
//     node cur;
//     while(!q.empty()){
//         cur=q.front();
//         q.pop();
//         if(!cur.code){
//             suc=1;
//             break;
//         }
//         for(int i=1;i<=9;i++){
//             int tmp0=operate(0,i,cur.code);
//             if(!vis[tmp0]){
//                 node tmp1;
//                 tmp1.ope=cur.ope;
//                 tmp1.ope.push_back(i);
//                 tmp1.code=tmp0;
//                 q.push(tmp1);
//                 vis[tmp0]=1;
//             }
//         }
//     }
//     cout<<"ehd"<<endl;
//     if(suc){
//         for(auto x:cur.ope){
//             cout<<x<<" ";
//         }
//     }
//     return 0;
// }