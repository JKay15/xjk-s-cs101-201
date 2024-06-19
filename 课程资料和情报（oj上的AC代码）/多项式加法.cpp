#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,num1,num2;
    cin>>t;
    cin.ignore();
    while(t--){
        string tmp;
        map<int,int,greater<int>> ans;
        for(int i=0;i<2;i++){
            getline(cin,tmp);
            istringstream iss(tmp);
            while(iss>>num1>>num2&&num2>=0)ans[num2]+=num1;
        }
        for(auto x:ans)if(x.second)cout<<"[ "<<x.second<<" "<<x.first<<" ] ";
        cout<<"\n";
    }
    return 0;
}

//粗心大意的错误，在最后op2写成op1了
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,num1,num2;
    cin>>t;
    cin.ignore();
    while(t--){
        string tmp;
        map<int,int> tmp1,tmp2;
        for(int i=0;i<2;i++){
            getline(cin,tmp);
            istringstream iss(tmp);
            while(iss>>num1>>num2&&num2>=0)if(i)tmp2[num2]+=num1;else tmp1[num2]+=num1;
        }
        vector<pair<int,int>> op1,op2,ans;
        for(auto x:tmp1)op1.push_back(x);
        for(auto y:tmp2)op2.push_back(y);
        int l1=0,l2=0,ll1=op1.size(),ll2=op2.size();
        while(l1<ll1&&l2<ll2){
            if(op1[l1].first<op2[l2].first)ans.push_back(op1[l1++]);
            else if(op1[l1].first>op2[l2].first)ans.push_back(op2[l2++]);
            else{
                ans.push_back({op1[l1].first,op1[l1].second+op2[l2].second});
                l1++;l2++;
            }
        }
        while(l1<ll1)ans.push_back(op1[l1++]);
        while(l2<ll2)ans.push_back(op2[l2++]);
        for(int i=ans.size()-1;i>=0;i--)if(ans[i].second)cout<<"[ "<<ans[i].second<<" "<<ans[i].first<<" ] ";
        cout<<"\n";
    }
    return 0;
}