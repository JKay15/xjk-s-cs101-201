#include <bits/stdc++.h>
using namespace std;
const int MAX = 150 + 5;
const int INF = 0x3f3f3f3f;
//纯dfs好像也行，只要把图建好了就没啥问题
int k,n,m;
struct Node {
	int v;
	int dis,c;
	int ne;
	Node() {}
	Node(int v,int w,int c):v(v),dis(dis),c(c) {}
} e[MAX*MAX],r[MAX*MAX];
struct Point {
	int id,dis,cost;
	bool friend operator < (Point a,Point b) {
		return a.dis>b.dis;
	}
};
int head[MAX],read[MAX];
bool vis[MAX];
int Dis[MAX];
int ans = INF,tote,totr;
void add(int u,int v,int w,int c) {
	e[++tote].v = v;
	e[tote].dis = w;
	e[tote].c = c;
	e[tote].ne = head[u];
	head[u] = tote;
}
void add2(int u,int v,int w,int c) {
	r[++totr].v = v;
	r[totr].dis = w;
	r[totr].c = c;
	r[totr].ne = read[u];
	read[u] = totr;
}
void Dijkstra(){
	memset(Dis,INF,sizeof Dis);
	priority_queue<Point>pq;
	Point now,cur;
	cur.id=n;cur.cost=0;cur.dis=0;
	Dis[n] = 0;
	pq.push(cur);
	while(pq.size()) {
		cur=pq.top(); pq.pop();
		if(vis[cur.id]) continue;
		vis[cur.id] = 1;
		for(int i=read[cur.id]; i!=-1; i=r[i].ne) {
			int cost=cur.cost+r[i].c;
			if(Dis[r[i].v]>cur.dis+r[i].dis) {
				Dis[r[i].v]=cur.dis+r[i].dis;
				now.id=r[i].v;now.cost=cost;now.dis=Dis[r[i].v];
				pq.push(now);
			}
		}
	}
}
struct A {
	int id,dis,c;
	A(){};
	A(int id,int dis,int c):id(id),dis(dis),c(c){}
	bool friend operator < (A a,A b) {
		return a.dis + Dis[a.id] > b.dis + Dis[b.id];
	}
};
int Astar(int st,int ed) {
	priority_queue< A > pq;
	pq.push(A(st,0,0));
	while(pq.size()) {
		A cur = pq.top();pq.pop();
		if(cur.id == ed) return cur.dis;
		for(int i = head[cur.id]; i != -1; i = e[i].ne) {
			if(cur.c + e[i].c <= k) pq.push(A(e[i].v,cur.dis + e[i].dis,cur.c + e[i].c));
		}
	}
	return -1;
}
int main() {
	cin>>k>>n>>m;
	int u,v,w,c;
	memset(head,-1,sizeof head);
	memset(read,-1,sizeof read);
	for(int i = 1; i<=m; i++) {
		scanf("%d%d%d%d",&u,&v,&w,&c);
		add(u,v,w,c);
		add2(v,u,w,c);
	}
	Dijkstra();
	printf("%d\n",Astar(1,n));
	return 0 ;
}
//没想到最短路，想着二分+bfs,发现数据很不合适
// int k,n,R,tmp1,tmp2,tmp3,tmp4;
// int len[105][105];
// int cost[105][105];
// struct node{
//     int id,len,cost;
//     node(int x,int y,int z):id(x),len(y),cost(z){}
// };
// bool check(int max_l,vector<int>* graph){
//     queue<node> q;
//     q.push({1,0,0});
//     while(!q.empty()){
//         node cur=q.front();
//         q.pop();
//         for(auto x:graph[cur.id]){
//             int cc=cur.cost+cost[cur.id][x];
//             int ll=cur.len+len[cur.id][x];
//             if(cc<=k&&ll<=max_l){
//                 if(x==n){
//                     return 1;
//                 }else{
//                     q.push({x,ll,cc});
//                 }
//             }
//         }
//     }
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>k>>n>>R;
//     vector<int> graph[n+5];
//     memset(cost,-1,sizeof(cost));
//     memset(len,-1,sizeof(len));
//     int l=0x7777777,r=0,res=-1;
//     for(int i=1;i<=R;i++){
//         cin>>tmp1>>tmp2>>tmp3>>tmp4;
//         l=min(l,tmp3),r+=tmp3;
//         if(cost[tmp1][tmp2]!=-1){
//             len[tmp1][tmp2]=min(len[tmp1][tmp2],tmp3);
//             cost[tmp1][tmp2]=min(cost[tmp1][tmp2],tmp4);
//         }else{
//             len[tmp1][tmp2]=tmp3;
//             cost[tmp1][tmp2]=tmp4;
//             graph[tmp1].push_back(tmp2);
//         } 
//     }
//     while(l<=r){
//         int mid=(l+r)/2;
//         if(check(mid,graph)){
//             res=mid;
//             r=mid-1;
//         }else l=mid+1;
//     }
//     cout<<res<<"\n";
//     return 0;
// }