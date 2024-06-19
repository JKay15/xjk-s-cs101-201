#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int l=0,r=0,parent=0,w,id;
    char _min;
    node(int w=0,char x=0,int y=0):w(w),id(y),_min(x){}
    bool operator<(const node&x)const{
        if(w==x.w)return _min>x._min;
        return w>x.w;
    }
};
unordered_map<char,string> dic;
vector<node> a;
priority_queue<node> q;
void build(int id,string name){
    if(!a[id].l){
        dic[a[id]._min]=name;
        return ;
    }
    build(a[id].l,name+"0");
    build(a[id].r,name+"1");
}
string decode(string x){
    string tmp="";
    int l=x.length(),i=0;
    while(i<l){
        int cur=q.top().id;
        while(a[cur].l){
            if(x[i++]=='0')cur=a[cur].l;
            else cur=a[cur].r;
        }
        tmp+=a[cur]._min;
    }
    return tmp;
}
string encode(string x){
    string tmp="";
    for(auto y:x)tmp+=dic[y];
    return tmp;
}
int main(){
    cin>>n;
    a.push_back({});
    for(int i=1;i<=n;i++){
        char x;int t;
        cin>>x>>t;
        a.push_back({t,x,i});
        q.push(a[i]);
    }
    int tag=n+1;
    while(q.size()>1){
        node cur1=q.top();
        q.pop();
        node cur2=q.top();
        q.pop();
        node tmp={cur1.w+cur2.w,min(cur1._min,cur2._min),tag++};
        tmp.l=max(cur1,cur2).id;tmp.r=min(cur1,cur2).id;
        a.push_back(tmp);
        q.push(tmp);
    }
    build(q.top().id,"");
    string tmp;
    while(cin>>tmp)cout<<((tmp[0]>='0'&&tmp[0]<='9')?decode(tmp):encode(tmp))<<"\n";
    return 0;
}