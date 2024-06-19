//我自己独立写的版本，限时成功
#include <bits/stdc++.h>
using namespace std;
vector<string> dict;
void similar(string tmp){
    int l=tmp.length();
    vector<string> ans;
    for(auto x:dict){
        if(x==tmp){
            cout<<tmp<<" is correct\n";
            return ;
        }
        int l1=x.length();
        if(l1>l+1||l1<l-1)continue;
        else{
            if(l1==l){
                int t=0;
                for(int i=0;i<l;i++){
                    if(tmp[i]!=x[i])t++;
                }
                if(t>1)continue;
                else ans.push_back(x);
            }else if(l1==l+1){
                if(x.substr(1,l1-1)==tmp||x.substr(0,l1-1)==tmp)ans.push_back(x);
                else{
                    for(int i=1;i<l1-1;i++){
                        string tt=x.substr(0,i)+x.substr(i+1,l1-i-1);
                        if(tt==tmp){
                            ans.push_back(x);
                            break;
                        }
                    }
                }
            }else{
                if(tmp.substr(1,l-1)==x||tmp.substr(0,l-1)==x)ans.push_back(x);
                else{
                    for(int i=1;i<l-1;i++){
                        string tt=tmp.substr(0,i)+tmp.substr(i+1,l-i-1);
                        if(tt==x){
                            ans.push_back(x);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<tmp<<":";
    for(auto x:ans)cout<<" "<<x;
    cout<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string tmp;
    while(cin>>tmp){
        if(tmp=="#")break;
        dict.push_back(tmp);
    }
    while(cin>>tmp){
        if(tmp=="#")break;
        similar(tmp);
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// using namespace std;


// vector<string> dict;

// bool isSimilar(string word1, string word2)
// {
//     int len1 = word1.length();
//     int len2 = word2.length();

//     if (len1 + 1 == len2)
//     {
//         // Case 1: Insertion
//         for (int i = 0; i < len2; i++)
//         {
//             if (word2.substr(0, i) + word2.substr(i + 1) == word1)
//             {
//                 return true;
//             }
//         }
//     }
//     else if (len1 == len2)
//     {
//         // Case 2: Replacement
//         int diff = 0;
//         for (int i = 0; i < len1; i++)
//         {
//             if (word1[i] != word2[i])
//             {
//                 diff++;
//                 if (diff > 1)
//                 {
//                     break;
//                 }
//             }
//         }
//         if (diff == 1)
//         {
//             return true;
//         }
//     }
//     else if (len1 - 1 == len2)
//     {
//         // Case 3: Deletion
//         for (int i = 0; i < len1; i++)
//         {
//             if (word1.substr(0, i) + word1.substr(i + 1) == word2)
//             {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// void solve(string x)
// {

//     vector<string> similarWords;
//     for (string word : dict)
//     {
//         if (word == x)
//         {
//             cout << x << " is correct" << endl;
//             return;
//         }
//         if (isSimilar(x, word))
//         {
//             similarWords.push_back(word);
//         }
//     }

//     cout << x << ":";
//     if (similarWords.empty())
//     {
//         cout << endl;
//     }
//     else
//     {
//         for (string word : similarWords)
//         {
//             cout << " " << word;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string tmp;
//     while (cin >> tmp)
//     {
//         if (tmp == "#")
//             break;
//         dict.push_back(tmp);
//     }
//     while (cin >> tmp)
//     {
//         if (tmp == "#")
//             break;
//         solve(tmp);
//     }

//     return 0;
// }