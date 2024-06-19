//写的不好的点是dfs部分，对于终止条件理解的不好，应该提前想好什么时候停的
//同时对于组合部分的想法也没有一开始就完全搞明白
//总之这题还是挺好的
#include <bits/stdc++.h>
using namespace std;
int m,com[25][25];
string s1,s2;
int comp(int x,int y){
    if(y>x)return 0;
    if(y==0)return 1;
    if(com[x][y])return com[x][y];
    return com[x][y]=(comp(x-1,y-1)+comp(x-1,y));
}
int dfs(string t1,string t2,bool first){
    int ans=1,num=0,l=t1.length();
    if(!l)return 1;
    auto pos=t2.rfind(t1[0]);
    while(pos!=t2.length()-1){
        ans*=dfs(t1.substr(0,pos+1),t2.substr(0,pos+1),1);
        num++;
        l=t1.length();
        t1=t1.substr(pos+1,l-pos-1);
        t2=t2.substr(pos+1,l-pos-1);
        pos=t2.rfind(t1[0]);
    }
    num++;
    l=t1.length();
    t1=t1.substr(1,l-1);
    t2=t2.substr(0,l-1);
    int mul=comp(m,num);
    if(first)return ans*dfs(t1,t2,0);
    return ans*mul*dfs(t1,t2,0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>m&&m){
        cin>>s1>>s2;
        cout<<dfs(s1,s2,1)<<"\n";
    }
    return 0;
}