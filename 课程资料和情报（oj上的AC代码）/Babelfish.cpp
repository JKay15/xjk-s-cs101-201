//学习一下奇特输入的处理
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,string> dict;
int main(){
    char str[11];
    while(1){
        char ori[11],trans[11];
        scanf("%s%s",trans,ori);
        dict.insert(pair{string(ori),string(trans)});
        cin.get();
        if(cin.peek()=='\n')break;
    }
    while(scanf("%s",str)!=EOF){
        string tmp{str};
        if(dict.find(tmp)!=dict.end())
            printf("%s\n",dict[tmp].c_str());
        else    
            printf("%s\n","eh");
    }
}