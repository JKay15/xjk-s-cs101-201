// #include <bits/stdc++.h>
// using namespace std;
// int n,tot=1;
// bool vis[1000005]={0};
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     while(cin>>n&&n){
//         cout<<"Test case #"<<(tot++)<<"\n";
//         string tmp;
//         cin>>tmp;
//         for(int i=0;i<n;i++)vis[i]=0;
//         for(int i=1;i<=n&&!vis[n-1];i++){
//             for(int j=i;j<n;j++){
//                 if(tmp[j]==tmp[j%i]){
//                     if((j+1)%i==0&&(j+1)/i>1&&!vis[j]){
//                         vis[j]=1;
//                         cout<<(j+1)<<" "<<(j+1)/i<<"\n";
//                     }
//                 }else break;
//             }
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n;
#define maxn 1000005
char s[maxn];
int f[maxn],b[maxn];
int main(){
    int cnt=1;
    scanf("%d",&n);
    while (n!=0) {
        printf("Test case #%d\n",cnt++);
        scanf("%s",s);
        f[0]=-1,f[1]=0;
        for (int i=2;i<=n;i++) {
            int k=f[i-1];
            while (k>=0&&s[k]!=s[i-1]) k=f[k];
            f[i]=k+1;
        }
        for (int i=2;i<=n;i++) {
            b[i]=0;
            if (i%2==0&&f[i]==i/2) b[i]=2;
            if (b[f[i]]&&i%(b[f[i]]+1)==0&&f[i]/b[f[i]]==i/(b[f[i]]+1)) 
                b[i]=b[f[i]]+1;
            if (b[i]) printf("%d %d\n",i,b[i]);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}

