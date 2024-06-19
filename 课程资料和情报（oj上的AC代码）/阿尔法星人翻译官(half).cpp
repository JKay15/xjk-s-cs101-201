// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     unordered_map<string, int> dic = {
//         {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
//         {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
//         {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
//         {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18},
//         {"nineteen", 19}, {"twenty", 20}, {"thirty", 30}, {"forty", 40},
//         {"fifty", 50}, {"sixty", 60}, {"seventy", 70}, {"eighty", 80},
//         {"ninety", 90}, {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
//     };
//     string input;
//     getline(cin, input);
//     stringstream ss(input);
//     string token;
//     vector<string> tokens;
//     while (ss >> token)tokens.push_back(token);
//     int sign = 1;
//     if (tokens[0] == "negative") {
//         sign = -1;
//         tokens.erase(tokens.begin());
//     }
//     int total=0,tmp=0;
//     for (auto& i : tokens){
//         if (i == "thousand" || i == "million"){
//             total += tmp * dic[i];
//             tmp = 0;
//         }else if(i == "hundred")tmp *= dic[i];
//         else tmp += dic[i];
//     }
//     cout<<sign*(total+tmp)<<endl;
//     return 0;
// }

//不知道为啥错了，可能是输入吧——不是的，需要吧20、30...90和之前的11..19和在一个tmp里面，我分析一下为啥
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> tmp={{"zero","one","two","three","four","five","six","seven","eight","nine"},{"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"},{"hundred"},{"thousand"},{"million"}};
vector<string> cont;
unordered_map<string,int> dict;
string t;
int dfs(int i,int start,int end){
    if(i<0||start>end)return 0;
    auto pos=find(cont.begin()+start,cont.begin()+end+1,tmp[i][0]);
    string tar=tmp[i][0];
    if(pos==cont.begin()+end+1){
        int l=tmp[i].size();
        for(int j=1;j<l;j++){
            pos=find(cont.begin()+start,cont.begin()+end+1,tmp[i][j]);
            if(pos!=cont.begin()+end+1){
                tar=tmp[i][j];
                break;
            }
        }
    }
    if(pos==cont.begin()+end+1)return dfs(i-1,start,end);
    int ans=dict[tar];
    int p1=dfs(i-1,start,pos-cont.begin()-1);
    int p2=dfs(i-1,pos-cont.begin()+1,end);
    return ((p1)?p1:1)*ans+p2;
}
int main(){
    for(int i=0;i<10;i++)dict.insert({tmp[0][i],i});
    for(int i=10;i<=20;i++)dict.insert({tmp[1][i-10],i});
    for(int i=30;i<100;i+=10)dict.insert({tmp[1][10+(i-20)/10],i});
    dict.insert({tmp[2][0],100});dict.insert({tmp[3][0],1000});dict.insert({tmp[4][0],1000000});
    while(cin>>t)cont.push_back(t);
    int len=cont.size();
    if(cont[0]=="negative")cout<<-dfs(4,1,len-1);
    else cout<<dfs(4,0,len-1);
    return 0;
}