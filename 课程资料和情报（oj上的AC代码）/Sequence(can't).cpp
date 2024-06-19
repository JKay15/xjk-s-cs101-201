#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[101],b[101];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[1]=a[1];
    for(int i=2;i<n;i++)
    {
        if(a[i]>b[i-1]&&a[i]>a[i+1])
            b[i]=max(a[i+1],b[i-1]);
        else if(a[i]<b[i-1]&&a[i]<a[i+1])
            b[i]=min(a[i+1],b[i-1]);
        else
            b[i]=a[i];
    }
    b[n]=a[n];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+fabs(a[i]-b[i]);
    }
    for(int i=2;i<=n;i++)
    {
        sum=sum+fabs(b[i-1]-b[i]);
    }
    printf("%d\n",sum);
    return 0;
}