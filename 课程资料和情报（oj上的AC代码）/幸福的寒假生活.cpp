// def dpHappi():
//     happi = [0]*45
//     for day in range(45):
//         for x in [x for x in vList if x[1]<=day]:
//             si = x[0]
//             ei = x[1]
//             vi = x[2]
//             if day == 0:
//                 happi[day]=max(vi,happi[day])
//             elif si>0:
//                 happi[day]=max(happi[day-1],happi[si-1]+vi,happi[day])
//             else:
//                 happi[day]=max(vi,happi[day],happi[day-1])
//     return happi[-1]
 
// n = int(input())
// dic = {"1.7":0,"1.8":1,"1.9":2,"1.10":3,"1.11":4,"1.12":5,"1.13":6,"1.14":7,"1.15":8,"1.16":9,"1.17":10,"1.18":11,"1.19":12,"1.20":13,"1.21":14,"1.22":15,"1.23":16,"1.24":17,"1.25":18,"1.26":19,"1.27":20,"1.28":21,"1.29":22,"1.30":23,"1.31":24,"2.1":25,"2.2":26,"2.3":27,"2.4":28,"2.5":29,"2.6":30,"2.7":31,"2.8":32,"2.9":33,"2.10":34,"2.11":35,"2.12":36,"2.13":37,"2.14":38,"2.15":39,"2.16":40,"2.17":41,"2.18":42,"2.19":43,"2.20":44}
// vList=[]
 
// for i in range (n):
//     s,e,v = input().split()
//     si=dic[s]
//     try:
//         ei=dic[e]
//     except KeyError:
//         continue
//     vi=int(v)
//     vList.append([si,ei,vi])
// print(dpHappi())
//不知道为啥我的dp是错的——————错在输入上了，不能如果前两个日期越界了就不输入第三个数了，这样会导致错位的！！！！
#include <bits/stdc++.h>
using namespace std;
int n,dp[45],c,mm;
string t1,t2;
int change(string t){
    auto x=t.find('.');
    return stoi(t.substr(x+1,t.length()-x-1))+((stoi(t.substr(0,x))==1)?(-7):(24));
}
struct node{
    int l,r,val;
    node(int a,int b,int c):l(a),r(b),val(c){};
    bool operator<(const node&x)const{
        if(l==x.l)return r<x.r;
        return l<x.l;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<node> cont;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1>>t2>>c;
        if(change(t2)<45)cont.push_back({change(t1),change(t2),c});
    }
    sort(cont.begin(),cont.end());
    dp[cont[0].r]=cont[0].val;
    for(int i=1;i<n;i++,mm=0){
        for(int j=cont[i].l-1;j>=0;j--)mm=max(mm,dp[j]);
        dp[cont[i].r]=max(dp[cont[i].r],mm+cont[i].val);
    }
    cout<<*max_element(dp,dp+45);
    return 0;
}