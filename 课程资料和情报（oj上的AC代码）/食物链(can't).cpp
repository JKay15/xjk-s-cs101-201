// 就是用3倍的并查积的存各种动物的关系

// 一倍存本身，二倍存猎物，三倍存天敌

// 唯一容易忽略的点就是：一的猎物的猎物 就是一的天敌

// 那么我们每次只要维护三个并查积的关系就可以了

#include <bits/stdc++.h>
using namespace std;
int father[300005],n,k,ans;
inline int read(){
    int sum=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
    return sum;
}
int find(int x){
    if(x!=father[x])father[x]=find(father[x]);
    return father[x];
}
void unity(int x,int y){
    int fx=find(father[x]),fy=find(father[y]);
    father[fx]=fy;
}
int main(){
    int x,y,z;
    n=read(),k=read();
    for(int i=1;i<=3*n;i++)father[i]=i;
    for(int i=0;i<k;i++){
        z=read(),x=read(),y=read();
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(z==1){
            if(find(x+n)==find(y)||find(x+2*n)==find(y)){ans++;continue;}
            unity(x,y);unity(x+n,y+n);unity(x+2*n,y+2*n);
        }else{
            if(x==y){ans++;continue;}
            if(find(x)==find(y)||find(x+2*n)==find(y)){ans++;continue;}
            unity(x,y+2*n);unity(x+n,y);unity(x+2*n,y+n);
        }
    }
    printf("%d\n",ans);
    return 0;
}
//想法很对，想到了给出更大的并查集，但是没想到因为有三个种类，需要开三倍的大小，维护关系，只开了两倍，并且对于eat的处理也是逻辑有问题的
// #include <bits/stdc++.h>
// using namespace std;
// const int maxn=50005;
// int father[maxn],n,k,tmp1,tmp2,tmp3,eat[maxn];
// void build(){
//     for(int i=1;i<=n;i++)father[i]=i;
// }
// int find(int x){
//     if(father[x]!=x){
//         return find(father[x]);
//     }
//     return x;
// }
// void union1(int x,int y){
//     int fx=find(x),fy=find(y);
//     if(fx==fy)return ;
//     else father[fy]=fx;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>n>>k;
//     build();
//     int total=0;
//     for(int i=1;i<=k;i++){
//         cin>>tmp1>>tmp2>>tmp3;
//         if(tmp2>n||tmp3>n){
//             total++;
//         }
//         else if(tmp1==2&&tmp2==tmp3){
//             total++;
//         }
//         else{
//             if(tmp1==1){
//                 int eat2=find(eat[tmp2]),eat3=find(eat[tmp3]);
//                 int f2=find(tmp2),f3=find(tmp3);
//                 int eeat2=find(eat[eat[tmp2]]),eeat3=find(eat[eat[tmp3]]);
//                 if(f2==eat3||eat2==f3||eeat3==f2||eeat2==f3){
//                     total++;
//                 }
//                 else union1(tmp2,tmp3);
//             }else{
//                 int f2=find(tmp2),f3=find(tmp3);
//                 if(f2==f3){
//                     total++;
//                 }
//                 else eat[tmp3]=f2;
//             }
//         }
//     }
//     cout<<total<<"\n";
//     return 0;
// }