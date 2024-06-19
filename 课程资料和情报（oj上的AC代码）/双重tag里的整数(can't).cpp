//python正则表达式，因为这道题是python程序设计的考试。。。。
// import re
 
// while True:
//     try:
//         s = input()
//         m = "<([A-Za-z]{1,5})>(.*)</\\1>"
//         lst = re.findall(m, s)
//         # print('第1次',lst,type(lst))
//         v = 0
//         if lst:
//             for i in lst:
//                 s = i[1]
//                 # print('第1次',s,type(s))
//                 m = ".<([A-Za-z]{1,5})>(.*?)</\\1>."
//                 nlst = re.findall(m, s)
//                 if nlst:
//                     # print('第2次',nlst)
//                     for j in nlst:
//                         s = j[1]
//                         m = "(\d+)"
//                         # print(s,type(s))
//                         result = re.findall(m, s)
//                         if result:
//                             # print(result)
//                             for n in result:
//                                 if n == '0' or (len(n) < 5 and n[0] != '0'):
//                                     print(n, end=" ")
//                                     v = 1
//         if v == 1:
//             print("")
//         else:
//             print("NONE")
//     except:
//         break
//太麻烦了，讨论的情况太多了，可能是我的切入角度不对吧
// #include <bits/stdc++.h>
// using namespace std;
// string tmp1;
// vector<string> ans; 
// void pro(string x){ 
//     int l=x.length();
//     string tmp="";
//     for(int i=0;i<l;i++){
//         if(x[i]>='0'&&x[i]<='9')tmp+=x[i];
//         else{
//             int l1=tmp.length();
//             if(l1>0&&l1<=4){
//                 if(l1==1)ans.push_back(tmp);
//                 else if(tmp[0]!='0')ans.push_back(tmp);
//             }
//             tmp="";
//         }
//     }
//     int l1=tmp.length();
//     if(l1>0&&l1<=4){
//         if(l1==1)ans.push_back(tmp);
//         else if(tmp[0]!='0')ans.push_back(tmp);
//     }
// }
// void dfs(bool stage,string str){
//     int l=str.length();
//     int cur=str.find('<');
//     while(cur<l&&cur>=0){
//         int r=str.find('>',cur);
//         if(r==-1)return;
//         else{
//             string tt=str.substr(cur+1,r-cur-1);
//             if(!all_of(tt.begin(),tt.end(),[](char&x){return isalpha(x);})){
//                 cur=str.find('<',r);
//                 continue;
//             }
//             vector<int> posi;
//             int where=str.find("</"+tt+">",r);
//             while(where!=-1){
//                 posi.push_back(where);
//                 where=str.find("</"+tt+">",where+1);
//             }
//             for(auto i:posi){
//                 int pos=i;
//                 if(pos==-1){
//                     cur=str.find('<',r);
//                     if(stage)break;
//                     continue;
//                 }else{
//                     if(!stage)dfs(1,str.substr(r+1,pos-r-1));
//                     else{
//                         pro(str.substr(r+1,pos-r-1));
//                         return;
//                     } 
//                     cur=str.find('<',pos+r-cur-1);
//                     if(stage)break;
//                     continue;
//                 }
//             }
            
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     while(getline(cin,tmp1)){
//         ans.clear();
//         dfs(0,tmp1);
//         if(ans.size()){
//             for(auto y:ans)cout<<y<<" ";
//             cout<<"\n";
//         }else cout<<"NONE\n";
//     }
//     return 0;
// }