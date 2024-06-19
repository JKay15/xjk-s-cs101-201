#include <bits/stdc++.h>
using namespace std;
unordered_set<string> dict;
unordered_set<string> vis;
struct node{
    string str;
    int step;
    node(){}
    node(int x,string s):str(s),step(x){}
};
string sta,en,tmp;
bool check(string x1,string x2){
    int diff=0,l=x1.length();
    for(int i=0;i<l;i++)diff+=(x1[i]!=x2[i]);
    return (diff==1);
}
int main(){
    cin>>sta>>en;
    while(cin>>tmp)dict.insert(tmp);
    queue<node> q;
    q.push({1,sta});
    int ans=-1;
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(check(cur.str,en)){
            ans=cur.step+1;
            break;
        }
        for(auto x:dict){
            int l=cur.str.length(),l1=x.length();
            if(vis.find(x)==vis.end()&&(l1==l)){
                if(check(x,cur.str)){
                    vis.insert(x);
                    q.push({cur.step+1,x});
                }
            }
        }
        if(ans!=-1)break;
    }
    if(ans!=-1)cout<<ans<<"\n";
    else cout<<"0\n";

    return 0;
}