//忘了初始化ans了，如果最初的排列就是最优的，ans就应该是最初的seq，而不是空的
//本质上是一道穷举+贪心的题目
#include <bits/stdc++.h>
using namespace std;
double a,b,c;
string name[3];
int x[3],y[3];
double dis(int x1,int y1,int x2,int y2){
    if(c>=a+b)return 1.0*(a*abs(x1-x2)+b*abs(y1-y2));
    else{
        int dx=abs(x1-x2),dy=abs(y1-y2);
        if(dx==dy)return 1.0*c*dx;
        else return min(1.0*(c*dx+b*abs(dy-dx)),1.0*(c*dy+a*abs(dy-dx)));
    }
}
double cost(vector<int> & seq){
    int cur_x=0,cur_y=0;
    double total=0;
    for(int i=0;i<3;i++){
        total+=dis(cur_x,cur_y,x[seq[i]],y[seq[i]]);
        cur_x=x[seq[i]];
        cur_y=y[seq[i]];
    }
    total+=dis(cur_x,cur_y,100,100);
    return total;
}
void pro(int i,string tmp){
    int tag=0,l=tmp.length();
    string cur;
    int j=l-1;
    for(;j>=0;j--){
        if(tmp[j]==' '){
            if(tag==0){
                y[i]=stoi(cur);
                cur="";
                tag++;
            }else if(tag==1){
                x[i]=stoi(cur);
                break;
            }
        }else{
            cur=tmp[j]+cur;
        }
    }
    name[i]=tmp.substr(0,j);
}
int main(){
    cin>>a>>b>>c;
    getchar();
    for(int i=0;i<3;i++){
        string tmp;
        getline(cin,tmp);
        pro(i,tmp);
    }
    vector<int> seq{0,1,2};
    vector<int> ans=seq;
    double total=cost(seq);
    while(next_permutation(seq.begin(),seq.end())){
        double tmp=cost(seq);
        if(tmp<total){
            total=tmp;
            ans=seq;
        }
    }
    for(int i=0;i<3;i++)cout<<name[ans[i]]<<" ";
    printf("\n%.2f",total);
    return 0;
}