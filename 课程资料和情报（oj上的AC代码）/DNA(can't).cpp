//状态压缩dp也行。。。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 9;
int f[1 << (maxn + 1)][maxn];//x为二进制表示的一维visited状态 y为当前字符串的最后一个基因片段
char genes[maxn + 1][20];
bool invalid[maxn + 1];
int l[maxn + 1];
int chong[maxn + 1][maxn + 1];
int n, minlen, base;
int dp(int state, int last) {
    if (f[state][last])
        return f[state][last];
    f[state][last] = 1 << 10;
    for (int i = 1; i <= n; i++) {
        int flag = state & (1 << i);
        if (flag) 
            f[state][last] = min(dp(state - (1 << i), i) + l[last] - chong[last][i], f[state][last]);
    }
    return f[state][last];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)cin >> genes[i];
        memset(f, 0, sizeof(f));
        minlen = 2 << 10;
        base = 1 << (n + 1);
        for (int i = 1; i <= n; i++) {
            invalid[i] = true;
            f[0][i] = l[i] = strlen(genes[i]);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i != j && invalid[i] && invalid[j] && strstr(genes[i], genes[j]) != NULL)
                {
                    invalid[j] = false;
                    base -= 1 << j;
                }
                if (i != j && invalid[i] && invalid[j]) {
                    int l0 = min(l[i], l[j]);
                    while (l0) {
                        if (strstr(genes[j], genes[i] + l[i] - l0) == genes[j])
                            break;
                        l0--;
                    }
                    chong[i][j] = l0;
                }
            }
        for (int i = 1; i <= n; i++)
            if (invalid[i])
                minlen = min(dp(base - (1 << i) - 2, i), minlen);
        printf("%d\n", minlen);
    }
    return 0;
}
// //预处理每两个字符串之间能接在哪里，并且及时剪枝，还没看懂pid>sum为什么要退出
// #include<bits/stdc++.h>
// using namespace std;
// int T,N,ans,sum;
// string s[20];
// int a[200],vis[20];
// int work(string a,string b)
// {
// 	int la=a.length();
// 	int lb=b.length();
// 	for(int j=0;j<la;j++)
// 	{
// 		int start=b.find(a.substr(j));
// 		if(start==0)return la-j;	
// 	}
// 	return 0;
// }
// void dfs(int x,int pid)
// {
// 	// if(pid>sum) return;
// 	if(pid==N){
// 		sum=min(ans,sum);
// 		return;
// 	}
// 	for(int i=0;i<N;i++)
// 	{
// 		if(vis[i]==1) continue;
// 		if(s[x].find(s[i])!=s[x].npos)
// 		{
// 			vis[i]=1;
// 			dfs(i,pid+1);
// 			vis[i]=0;
// 		}
// 		else
// 		{
// 			int l=a[x*10+i];
// 			ans+=(s[i].length()-l);
// 			vis[i]=1;
// 			dfs(i,pid+1);
// 			vis[i]=0;
// 			ans-=(s[i].length()-l);
// 		}
// 	}
// } 
// void init()
// {
// 	memset(vis,0,sizeof(vis));
// 	memset(a,0,sizeof(a));
// 	ans=0x3f3f3f3f;
// 	sum=0x3f3f3f3f;
// 	for(int i=0;i<N;i++)
// 		s[i]=' ';
// }
// int main()
// {
// 	cin>>T;
// 	while(T--)
// 	{
// 		cin>>N;
// 		init();
// 		for(int i=0;i<N;i++)cin>>s[i];
// 		for(int i=0;i<N;i++)
// 		{
// 			for(int j=0;j<N;j++)
// 			{
// 				if(i==j) continue;
// 				a[i*10+j]=work(s[i],s[j]);
// 			}
// 		}
// 		for(int i=0;i<N;i++)
// 		{
// 			vis[i]=1;
// 			ans=s[i].length();
// 			dfs(i,1);
// 			vis[i]=0;
// 		}
// 		cout<<sum<<endl;
// 	}
// 	return 0;
// }
//正确的，但是穷举太慢，每次看能接在哪也太慢
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// pair<int,string> LIS(vector<string>& dict,int i,int pre,string DNA){
//     if(i==n)return {DNA.length(),DNA};
//     int l_t=DNA.length();
//     auto pos=DNA.substr(pre,l_t-pre).find(dict[i]);
//     if(pos!=string::npos){
//         return LIS(dict,i+1,pos+pre,DNA);
//     }else{
//         int l=dict[i].length();
//         for(int j=min(l_t-pre,l-1);j>=1;j--){
//             if(l_t-j+1>=pre&&DNA.substr(l_t-j,j)==dict[i].substr(0,j)){
//                 return LIS(dict,i+1,l_t-j,DNA+dict[i].substr(j,l-j));
//             }
//         }
//         return LIS(dict,i+1,l_t,DNA+dict[i]);
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<string> dict(n);
//         for(int i=0;i<n;i++)cin>>dict[i];
//         sort(dict.begin(),dict.end());
//         int ans=0x7777777;
//         string ans1;
//         do{
//             auto p1=LIS(dict,1,0,dict[0]);
//             if(p1.first<ans){
//                 ans=p1.first;
//                 ans1=p1.second;
//             }
//             // ans=min(ans,LIS(dict,1,0,dict[0]));
//         }while(next_permutation(dict.begin(),dict.end()));
//         cout<<ans<<"\n"<<ans1<<"\n";
//     }
//     return 0;
// }
//错误的，无法改变字符串的先后顺序
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// pair<int,string> pro(vector<string>& dict,int i,string res){
//     if(i==n)return {res.length(),res};
//     //接在后面和接在前面
//     pair<int,string> p1=pro(dict,i+1,dict[i]+res),p2=pro(dict,i+1,res+dict[i]);
//     int ans;string ans1;
//     if(p1.first<p2.first){
//         ans=p1.first;
//         ans1=p1.second;
//     }else{
//         ans=p2.first;
//         ans1=p2.second;
//     }
//     // int ans =min(pro(dict,i+1,dict[i]+res),pro(dict,i+1,res+dict[i]));
//     //放中间
//     if(res.find(dict[i])!=string::npos){
//         p1=pro(dict,i+1,res);
//         if(p1.first<ans){
//             ans=p1.first;
//             ans1=p1.second;
//         }
//         // ans=min(ans,pro(dict,i+1,res));
//     }
//     //前后部分接
//     int l1=res.length(),l2=dict[i].length();
//     for(int j=min(l1,l2)-1;j>=1;j--){
//         if(res.substr(0,j)==dict[i].substr(l2-j,j)){
//             p1=pro(dict,i+1,dict[i].substr(0,l2-j)+res);
//             if(p1.first<ans){
//             ans=p1.first;
//             ans1=p1.second;
//             }
//             // ans=min(ans,pro(dict,i+1,dict[i].substr(0,l2-j)+res));
//         }
//         if(res.substr(l1-j,j)==dict[i].substr(0,j)){
//             p1=pro(dict,i+1,res+dict[i].substr(j,l2-j));
//             if(p1.first<ans){
//                 ans=p1.first;
//                 ans1=p1.second;
//             }
//             // ans=min(ans,pro(dict,i+1,res+dict[i].substr(j,l2-j)));
//         }
//     }
//     return {ans,ans1};
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<string> dict(n);
//         for(int i=0;i<n;i++)cin>>dict[i];
//         auto ans=pro(dict,1,dict[0]);
//         // cout<<pro(dict,1,dict[0])<<"\n";
//         cout<<ans.first<<"\n"<<ans.second<<"\n";
//     }
//     return 0;
// }