// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n,tmp;
//     string ans;
//     cin>>n;
//     vector<int> num,vis(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>tmp;
//         if(tmp<1||tmp>n){cout<<"NO";return 0;}
//         if(vis[tmp]){
//             if(num.back()!=tmp){cout<<"NO";return 0;}
//             else{
//                 num.pop_back();
//                 ans+="POP ";
//                 ans+=to_string(tmp);
//                 ans+="\n";
//             }
//         }else{
//             for(int j=1;j<=tmp;j++){
//                 if(!vis[j]){
//                     num.push_back(j);
//                     vis[j]=1;
//                     ans+="PUSH ";
//                     ans+=to_string(j);
//                     ans+="\n";
//                 }
//             }
//             num.pop_back();
//             ans+="POP ";
//             ans+=to_string(tmp);
//             ans+="\n";
//         }
//     }
//     cout<<ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int n;
bool judge(vector<int> &a){
    stack<int> x,y;
    for(int i=a.size()-1;i>=0;--i)x.push(a[i]);
    for(int i=1;i<=n;++i){
        y.push(i);
        while(!y.empty()&&x.top()==y.top()){
            x.pop();
            y.pop();
        }
    }
    if(!x.empty()){printf("NO");return 1;}
    else return 0;
}
void f(vector<int> &a){
    stack<int> x,y;
    for(int i=a.size()-1;i>=0;--i)x.push(a[i]);
    for(int i=1;i<=n;++i){
        y.push(i);
        printf("PUSH %d\n",i);
        while(!y.empty()&&x.top()==y.top()){
            printf("POP %d\n",x.top());
            x.pop();
            y.pop();
        }
    }
}
int main(){
    int x,y;
    scanf("%d",&n);
    vector<int> aa(n);
    for(int i=0;i<n;++i)scanf("%d",&aa[i]);
    if(aa.size()!=n){printf("NO");return 0;}
    if(judge(aa))return 0;
    else f(aa);
}