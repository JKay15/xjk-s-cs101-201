#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp;
    cin>>tmp;
    int l=tmp.length();
    vector<int> dp[l],prev[l];
    for(int i=0;i<l;i++){
        dp[i].resize(8);
        prev[i].assign(8,-1);
    }
    dp[0][(tmp[0]-'0')%8]=1;
    for(int i=1;i<l;i++){
        dp[i][(tmp[i]-'0')%8]=1;
        for(int j=0;j<8;j++){
            if(dp[i-1][j]){
                dp[i][(j*10+tmp[i]-'0')%8]=1;
                prev[i][(j*10+tmp[i]-'0')%8]=j;
                dp[i][j]=dp[i-1][j];
                prev[i][j]=j;
            }
        }
    }
    for(int i=0;i<l;i++){
        if(dp[i][0]){
            string ans="";
            int curI=i,curJ=0;
            while(1){
                if(prev[curI][curJ]==-1||prev[curI][curJ]!=curJ)ans.append(1,tmp[curI]);
                if(prev[curI][curJ]==-1)break;
                curJ=prev[curI][curJ];
                curI--;
            }
            cout<<"YES\n";
            reverse(ans.begin(),ans.end());
            cout<<ans;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string tmp;
//     cin>>tmp;
//     int s=0,l=tmp.length(),tag=0;
//     string ans="";
//     while(tmp[s]=='0'&&s<l)s++;
//     if(s!=0){
//         tag=1;
//         ans="0";
//     }
//     else{
//         if(l-s>=3){
//         for(int i=s;i<l;i++){
//         string num="";num+=tmp[i];
//         if(stoi(num)%8==0){
//             tag=1;
//             ans=num;
//             break;
//         }
//         for(int j=i+1;j<l;j++){
//         num+=tmp[j];
//         if(stoi(num)%8==0){
//             tag=1;
//             ans=num;
//             break;
//         }
//         for(int k=j+1;k<l;k++){
//         num+=tmp[k];
//         if(stoi(num)%8==0){
//             tag=1;
//             ans=num;
//             break;
//         }
//         num=num.substr(0,2);
//         }
//         if(tag)break;
//         num=num.substr(0,1);
//         }
//         if(tag)break;
//         }
//         }else{
//             if(l-s==0){
//                 ans="0";
//                 tag=1;
//             }
//             else if(l-s==1){
//                 tag=((stoi(to_string(tmp[s]))%8)?0:1);
//                 if(tag)ans+=tmp[s];
//             }
//             else{
//                 string ans1="",ans2="",ans3="";
//                 ans1+=tmp[s];ans2+=tmp[s+1];ans3=ans1+ans2;
//                 if(!(stoi(ans1)%8)||!(stoi(ans2)%8)||!(stoi(ans3)%8))tag=1;
//                 if(!(stoi(ans1)%8))ans=ans1;
//                 if(!(stoi(ans2)%8))ans=ans2;
//                 if(!(stoi(ans3)%8))ans=ans3;
//             }
//         }
//     }
//     cout<<((tag)?"YES":"NO");
//     if(tag)cout<<"\n"<<ans;
//     return 0;
// }
#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define prev sadasdjksgjkasjdklaj
 
 
string s;
int n;

 
int main() {
 
    getline(cin, s);
    n = sz(s);
    bool dp[n+1][8];
    int prev[n+1][8];
    memset(prev, -1, sizeof(prev));
 
    dp[0][(s[0] - '0') % 8] = true;
 
    for (int i = 1; i < n; i++) {
        dp[i][(s[i] - '0') % 8] = true;
 
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                dp[i][(j * 10 + s[i] - '0') % 8] = true;
                prev[i][(j * 10 + s[i] - '0') % 8] = j;
 
                dp[i][j] = true;
                prev[i][j] = j;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curJ = 0;
 
            while (true) {
                if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
                    ans.append(1, s[curI]);
                }
 
                if (prev[curI][curJ] == -1) break;
 
                curJ = prev[curI][curJ];
                curI--;
            }
 
            puts("YES");
            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }
    }
 
    puts("NO");
 
    return 0;
}