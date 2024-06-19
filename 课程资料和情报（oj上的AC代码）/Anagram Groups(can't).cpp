//超时了
// #include <bits/stdc++.h>
// using namespace std;
// struct sset{
//     priority_queue<string,vector<string>,greater<string>> ele;
//     int num[26]={0};
//     sset(string x){
//         for(auto y:x)num[y-'a']++;
//         ele.push(x);
//     }
//     bool operator<(const sset& x)const{
//         if(ele.size()==x.ele.size())return ele.top()<x.ele.top();
//         return ele.size()>x.ele.size();
//     }
//     bool check(string &x){
//         int num1[26]={0};
//         for(auto y:x)num1[y-'a']++;
//         for(int i=0;i<26;i++)if(num1[i]!=num[i])return 0;
//         return 1;
//     }
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<sset> cont;
//     string tmp;
//     while(cin>>tmp){
//         bool ok=0;
//         for(auto& x:cont){
//             if(x.check(tmp)){
//                 x.ele.push(tmp);
//                 ok=1;
//                 break;
//             }
//         }
//         if(!ok)cont.push_back({tmp});
//     }
//     sort(cont.begin(),cont.end());
//     int ss=cont.size();
//     for(int i=0;i<5&&i<ss;i++){
//         cout<<"Group of size "<<cont[i].ele.size()<<": ";
//         while(!cont[i].ele.empty()){
//             cout<<cont[i].ele.top()<<" ";
//             cont[i].ele.pop();
//         }
//         cout<<".\n";
//     }
//     return 0;
// }
//字典树,没看懂
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
string str;
int idx[maxn];
vector<string> g[maxn];
bool cmp(int i,int j)
{
    if(g[i].size()!=g[j].size())
        return g[i].size()>g[j].size();
    else if(g[i].size() && g[j].size())
        return g[i][0]<g[j][0];
}
namespace Trie
{
    const int SIZE=maxn*2;
    int sz,tot;
    struct TrieNode{
        int ed;
        int nxt[26];
    }trie[SIZE];
    void init(){sz=1, tot=0;}
    int insert(const string& s)
    {
        int p=1;
        for(int i=0;i<s.size();i++)
        {
            int ch=s[i]-'a';
            if(!trie[p].nxt[ch]) trie[p].nxt[ch]=++sz;
            p=trie[p].nxt[ch];
        }
        return trie[p].ed?trie[p].ed:(trie[p].ed=++tot);
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Trie::init();
    while(cin>>str)
    {
        string tmp=str;
        sort(tmp.begin(),tmp.end());
        int t=Trie::insert(tmp);
        g[t].push_back(str);
    }

    for(int i=1;i<=Trie::tot;i++) idx[i]=i;
    sort(idx+1,idx+Trie::tot+1,cmp);

    for(int i=1;i<=5 && g[idx[i]].size()>0;i++)
    {
        vector<string>& v=g[idx[i]];
        cout<<"Group of size "<<v.size()<<": ";
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int k=0;k<v.size();k++) cout<<v[k]<<' ';
        cout<<".\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
struct Word{//单词的输入
	char ord[30];//组成成分
	char sou[30];//原单词
}w[30000];
struct seq{//同一类的单词序列
	int times;//次数
	int first;//首个单词的位置
	int end;//最后一个单词的位置
}v[30000];
bool cmp_w(Word x,Word y){//用于对所有单词排序
	if(strcmp(x.ord,y.ord)==0)
		return strcmp(x.sou,y.sou)<0?true:false;
	return strcmp(x.ord,y.ord)<0?true:false;
}
bool cmp_v(seq x,seq y){//用于判断同一类的次数相同时的输出顺序
	if(x.times == y.times)
		return strcmp(w[x.first].sou,w[y.first].sou)<0?true:false;
	return x.times>y.times;
}
int main(){
	char str[100];
	char tmp[100];
	int n = 0;
	while(~scanf("%s",str)){
		strcpy(w[n].sou,str);
		sort(str,str+strlen(str));//原单词排序得到标识
		strcpy(w[n].ord,str);
		++n;
	}
	sort(w,w+n,cmp_w);//将单词排序
	int k = 0;
	for(int i = 0;i<n;++i){//寻找同一类的单词
		int cnt = 0,t = i;
		while(!strcmp(w[i].ord,w[i+1].ord)&&i<n){
			++i;
			++cnt;
		}
		v[k].first = t;//标记这一类单次的起止位置
		v[k].end = i;
		v[k].times = cnt+1;
		++k;
	}
	sort(v,v+k,cmp_v);//对每一类进行排序
	for(int i = 0;i<5&&i<k;++i){
		printf("Group of size %d: %s",v[i].times,w[v[i].first].sou);
		for(int j = v[i].first+1;j<=v[i].end;++j)
			if(strcmp(w[j].sou,w[j-1].sou)!=0)
				printf(" %s",w[j].sou);
		printf(" .\n");
	}
	return 0;
}
