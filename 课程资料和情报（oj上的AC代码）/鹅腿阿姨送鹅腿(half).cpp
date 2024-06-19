//知道要贪心，但是这么好的贪心，只考虑加满油范围上有无满足要求的点，还是没法直接想到
//以及用单调栈和单调队列的优化是第一次同时使用
#include <bits/stdc++.h>
using namespace std;
double d1,d2,c,m,res,ans,i;
int n,cur=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>d1>>c>>d2>>m>>n;
    vector<double> d(n+2),p(n+2);
    deque<int> rm,stack;
    rm.assign(n+2,-1);
    d[0]=0,p[0]=m;
    for(int i=1;i<=n;i++)cin>>d[i]>>p[i];
    d[n+1]=d1,p[n+1]=0;
    stack.push_back(0);
    for(int i=1;i<=n+1;i++){
        while(!stack.empty()&&p[i]<p[stack.back()]){
            rm[stack.back()]=i;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    stack.clear();
    for(int i=0;i<=n;i++){
        while(!stack.empty()&&stack.front()<=i)stack.pop_front();
        for(;cur<=n+1&&d[cur]<=d[i]+c*d2;cur++){
            while(!stack.empty()&&p[stack.back()]>=p[cur])stack.pop_back();
            stack.push_back(cur);
        }
        //离我最近的比我小的在我加满油的范围内，则直接去那个地方，如果油不够，恰好加够
        if(rm[i]!=-1&&d[rm[i]]<=d[i]+c*d2){
            if(res<d[rm[i]]-d[i]){ans+=(d[rm[i]]-d[i]-res)*p[i]/d2;res=0;}
            i=rm[i]-1;
        }else{
            //加满油能直接到终点了
            if(d[i]+c*d2>=d1){
                if(d[i]+res<d1)printf("%.2f",ans+(d1-d[i]-res)*p[i]/d2);
                else printf("%.2f",ans);
                return 0;
            }
            //否则，前往范围内最小的位置考虑,先加满油
            if(!stack.empty()){
                ans+=(c*d2-res)*p[i]/d2;
                res=c*d2-(d[stack.front()]-d[i]);
                i=stack.front()-1;
            }else{
                printf("No Solution");
                return 0;
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}