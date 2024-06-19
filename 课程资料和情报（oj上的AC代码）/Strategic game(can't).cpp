//没有想到dp，用了一种很慢的贪心
// #include <bits/stdc++.h>
// using namespace std;
// int m;
// struct node{
//     unordered_set<int> cont;
//     int id;
// };
// string tmp;
// vector<node> edges;
// bool comp(node& x,node& y){
//     return x.cont.size()>y.cont.size();
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>m){
//         edges.clear();
//         edges.resize(m);
//         cin.ignore();
//         int num=0;
//         for(int i=0;i<m;i++){
//             getline(cin,tmp);
//             int where=stoi(tmp.substr(0,tmp.find(':')));
//             int pos=tmp.find(')'),l=tmp.length();
//             edges[where].id=where;
//             if(pos==l-1)continue;
//             tmp=tmp.substr(pos+2,l-pos-2);
//             istringstream iss(tmp);
//             while(iss>>pos){
//                 num++;
//                 edges[where].cont.insert(pos);
//                 edges[pos].cont.insert(where);
//             }
//         }
//         int ans=0;
//         sort(edges.begin(),edges.end(),comp);
//         unordered_set<int> x;
//         while(x.size()<num){
//             for(auto y:edges[ans].cont)x.insert(y);
//             ans++;
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// int m;
// struct node{
//     unordered_set<int> cont;
//     int id;
// };
// string tmp;
// vector<node> edges;
// bool comp(node& x,node& y){
//     return x.cont.size()>y.cont.size();
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>m){
//         edges.clear();
//         edges.resize(m);
//         cin.ignore();
//         for(int i=0;i<m;i++){
//             getline(cin,tmp);
//             int where=stoi(tmp.substr(0,tmp.find(':')));
//             int pos=tmp.find(')'),l=tmp.length();
//             edges[where].id=where;
//             if(pos==l-1)continue;
//             tmp=tmp.substr(pos+2,l-pos-2);
//             istringstream iss(tmp);
//             while(iss>>pos){
//                 edges[where].cont.insert(pos);
//                 edges[pos].cont.insert(where);
//             }
//         }
//         int ans=0;
//         sort(edges.begin(),edges.end(),comp);
//         while(edges[ans].cont.size()){
//             ans++;
//             auto& cc=edges[ans-1].cont;
//             for(int i=ans;i<m;i++){
//                 if(cc.find(edges[i].id)!=cc.end())edges[i].cont.erase(edges[ans-1].id);
//             }
//             sort(edges.begin()+ans,edges.end(),comp);
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N = 1510;
int f[N][2];
int h[N],e[N*2],ne[N*2],idx;
void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u,int fa){
	f[u][0] = 0;
	f[u][1] = 1;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j = e[i];
		if(j == fa) continue;
		dfs(j,u);
		f[u][0] += f[j][1];
		f[u][1] += min(f[j][0],f[j][1]);
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(h,-1,sizeof h);
		idx=0;
		for(int i=1;i<=n;i++){
			int x,k,y;
			scanf("%d:(%d)",&x,&k);
			while(k--){
				scanf("%d",&y);
				add(x,y);
				add(y,x);
			}
		}
		dfs(0,0);
		int ans = min(f[0][0],f[0][1]);
		cout<<ans<<"\n";
	}
	return 0;
}
