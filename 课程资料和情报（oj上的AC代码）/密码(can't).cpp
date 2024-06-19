#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
	int n;
	int num;
	while(scanf("%d",&n)&&n!=0){
		int x[1000]={0};
		int a[1000];
	int b[1000];
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		a[k]=i;
		b[i]=k;
	}
	for(int m=1;m<=n;m++){
		int i=m;
		int j;
		while(1){
			j=a[i];
			if(a[m]==a[j]){
				x[m]++;
				break;
			}
			else{
				i=j;
				j=a[i];
				x[m]++;
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	//cout<<endl;
	int k;
	while(scanf("%d",&k)!=EOF&&k!=0){
		num=0;
		string str;
		getchar();
		getline(cin,str);
		int y=str.size();
		if(k==0&&str[0]=='0') break;
		if(str.size()<=n){
			for(int i=1;i<=n-y;i++) str+=' ';
		}
		//cout<<str<<endl;
		char ss[1000];
		for(int i=1;i<=n;i++){
			int num=i;
			for(int j=1;j<=k%x[i];j++){
				num=b[num];
			}
			ss[num-1]=str[i-1];
		}
		ss[n]='\0';
		puts(ss);
	}
	cout<<endl;
	}
}
/*
10
4 5 3 7 2 8 1 6 10 9
1 Hello Bob
1995 CERC
200000 TRECT*/
// #include <bits/stdc++.h>
// using namespace std;
// int n,k;
// string tmp;
// vector<int> code(205);
// void Switch(string &str1,string &str2,vector<int>& s){
//     for(int i=0;i<n;i++)str2[s[i]-1]=str1[i];
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     while(cin>>n&&n){
//         for(int i=1;i<=n;i++)cin>>code[i];
//         vector<vector<int>> circle;
//         vector<unordered_map<int,int>> order;
//         vector<int> vis(n+1);
//         int tag=1;
//         for(int i=1;i<=n;i++){
//             if(!vis[i]){
//                 vector<int> tmp;
//                 unordered_map<int,int> tmp1;
//                 int tag1=0;
//                 tmp.push_back(i);
//                 tmp1[i]=tag1++;
//                 vis[i]=tag;
//                 int cur=code[i];
//                 while(cur!=i){
//                     vis[cur]=tag;
//                     tmp1[cur]=tag1++;
//                     tmp.push_back(cur);
//                     cur=code[cur];
//                 }
//                 circle.push_back(tmp);
//                 order.push_back(tmp1);
//                 tag++;
//             }
//         } 
//         while(cin>>k&&k){
//             getchar();
//             getline(cin,tmp);
//             int l=tmp.length();
//             for(int i=1;i<=n-l;i++)tmp+=' ';
//             string ans=tmp;
//             vector<int> shuxu;
//             for(int i=1;i<=n;i++){
//                 int s=circle[vis[i]-1].size();
//                 shuxu.push_back(circle[vis[i]-1][(order[vis[i]-1][i]+k)%s]);
//             }
//             Switch(tmp,ans,shuxu);
//             cout<<ans<<"\n";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }