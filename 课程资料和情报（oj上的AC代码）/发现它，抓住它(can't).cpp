#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int set1[MAXN], a[MAXN];
int t, n, m, fx, fy, x, y;
int Find_set1(int x) {
    if (x == set1[x]) return x;
    int t = Find_set1(set1[x]);
    a[x] = (a[set1[x]] + a[x]) % 2;
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<"\n";
    return set1[x] = t;
}
void Union(int x, int y) {
    int fx = Find_set1(x);
    int fy = Find_set1(y);
    set1[fx] = fy;
    if (a[y] == 0)
        a[fx] = 1 - a[x];
    else a[fx] = a[x];
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<"\n";
}
int main() {
    char ch;
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; i++) {
            set1[i] = i;
            a[i] = 0;
        }
        while(m--){
            scanf(" %c %d %d", &ch, &x, &y);
            if (ch == 'A') {
                fx = Find_set1(x);
                fy = Find_set1(y);
                if (fx != fy)
                    printf("Not sure yet.\n");
                else if (a[x] == a[y])
                    printf("In the same gang.\n");
                else printf("In different gangs.\n");
            } else Union(x, y);
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
//没想出来错在哪里了
// #include <bits/stdc++.h>
// using namespace stdw;
// const int maxn = 100005;
// int t,n,m,tag[maxn],cnt,num[maxn<<1],id1,id2;
// void change(int id1,int id2){
//     num[num[tag[id2]+maxn]+maxn]=-num[tag[id1]+maxn];
//     num[num[-tag[id2]+maxn]+maxn]=num[tag[id1]+maxn];
//     tag[id2]=-num[tag[id1]+maxn];
// }
// int main(){ 
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin>>t;
//     while(t--){
//         cin>>n>>m;
//         cnt=0;
//         for(int i=1;i<=n;i++)tag[i]=0;
//         for(int i=-n+maxn;i<=n+maxn;i++)num[i]=0;
//         while(m--){
//             char x;
//             cin>>x>>id1>>id2;
//             if(x=='A'){
//                 if(tag[id1]&&tag[id2]){
//                     if(num[tag[id1]+maxn]==num[tag[id2]+maxn])cout<<"In the same gang.\n";
//                     else if(num[tag[id1]+maxn]==-num[tag[id2]+maxn])cout<<"In different gangs.\n";
//                     else cout<<"Not sure yet.\n";
//                 }else cout<<"Not sure yet.\n";
//                 continue;
//             }
//             if(!tag[id1]&&!tag[id2]){
//                 tag[id1]=++cnt;
//                 tag[id2]=-cnt;
//                 num[cnt+maxn]=cnt;
//                 num[-cnt+maxn]=-cnt;
//             }else if(tag[id1]&&!tag[id2])tag[id2]=-num[tag[id1]+maxn];
//             else if(!tag[id1]&&tag[id2])tag[id1]=-num[tag[id2]+maxn];
//             else{
//                 if(abs(num[tag[id1]+maxn])<abs(num[tag[id2]+maxn]))change(id1,id2);
//                 else change(id2,id1);
//             }
//         }
//     }
//     return 0;
// }