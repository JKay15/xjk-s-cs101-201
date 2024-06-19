#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,h;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	vector<node> trees(n);
	for(int i=0;i<n;i++)cin>>trees[i].x>>trees[i].h;
	int total=1,cur=trees[0].x;
	for(int i=1;i<n;i++){
		if(trees[i].x-trees[i].h<=cur){
			if(i<n-1&&trees[i].x+trees[i].h<trees[i+1].x){
				total++;
				cur=trees[i].x+trees[i].h;
			}else if(i==n-1)total++;
			else cur=trees[i].x;
		}else{
			total++;
			cur=trees[i].x;
		} 
	}
	cout<<total<<"\n";
	return 0;
}