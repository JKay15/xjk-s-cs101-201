//拉了，没看出来贪心的策略，选择了错误的策略
#include <bits/stdc++.h>
char a[50];
int main()
{
    int t, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s %d", a, &b);
        int l = strlen(a);
        for (int i = 1; i <= b; i++)
        {
            for (int j = 0; j < l - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    for (int k = j; k < l - 1; k++)a[k] = a[k + 1];
                    break;
                }
            }
            l--;
        }
        for (int i = 0; i < l; i++)printf("%c", a[i]);
        printf("\n");
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// int num[10],k;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         memset(num,0,sizeof(num));
//         string tmp;
//         cin>>tmp>>k;
//         for(auto x:tmp)num[x-'0']++;
//         int total[10];
//         for(int i=1;i<10;i++)total[i]=num[i];
//         for(int i=9;i>0;i--){
//             if(num[i]>=k){
//                 num[i]-=k;
//                 break;
//             }else{
//                 k-=num[i];
//                 num[i]=0;
//             }
//         }
//         int res[10]={0};
//         for(auto x:tmp){
//             res[x-'0']++;
//             if(res[x-'0']+num[x-'0']>total[x-'0'])cout<<x;
//         }
//     }
//     return 0;
// }