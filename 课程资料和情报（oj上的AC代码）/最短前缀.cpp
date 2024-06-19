//计概A的时候写的代码
#include <bits/stdc++.h>
using namespace std;
char a[2010][30];
int check(int i,int n)
{
	int index=0;
	for(int j=0;j<=n;j++){
		if(j!=i){
			int t=0;
			while(a[i][t]==a[j][t]){
				t++;
			}
			if(a[i][t]=='\0'){
				t--;
			}
			if(t>index){
				index=t;
			}
		}
	}
	return index;
}
int main()
{
	int n=0;
	while (scanf("%s",a[n++])!=EOF);
	n--;
	for(int i=0;i<=n-1;i++){
		int b=check(i,n-1);
		cout<<a[i]<<" ";
		for(int j=0;j<=b;j++)cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}