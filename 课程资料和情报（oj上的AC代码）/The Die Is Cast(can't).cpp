// 题目的意思就是需要一个程序根据一张照片来得出照片中各个骰子的点数

// 简化为一个二维数组，像素简化为只有3中，‘.’代表背景,'*'代表骰子,'X'代表骰子上的点数

// 一块边与边相连互相联通的'X'和'*'就是代表照片中的骰子，一块联通的'X'代表的是一个点

// 做完之后看别人的都是用深搜吧，大概是递归的。我想的是遍历，按行从左到右遍历。之所以不用递归就是怕栈空间不够。。不过这道题不太可能。

// 递归的效率应该也是没有遍历好的吧。毕竟函数调用是有损耗的。


// 用遍历的话唯一保证的就是左边和上边的元素是遍历过的，为了标记已遍历到的非背景像素是属于哪个骰子的，将已遍历到的元素赋予全局唯一的值，可以使用一个int数组之类的来保存。同时要用map<全局标记，点数值>来储存骰子标号和点数对，当让用hash_map存的话，查找和插入值的速度会更快，然而vs2015不让用就算了，好像被取消了？。影响并不大。

// 当前遍历到的元素分三种情况

// 1.‘.’直接continue

// 2.'*'如果上边元素和左边元素都是'*'或者'X'那说明上面和左边，并且上面和左边标记为不同的骰子，那说明要把这两个骰子合起来看作一个骰子，将其合并并要更新对应数组中的标记值(这个得用递归了)，这时候骰子的点数和应该是两个骰子点数的和

//       如果左边和上面标记的是相同的骰子，那更新当前的元素的标记值为这个值就可以了就可以了

//       如果左边和上面标记只有一个被标记为骰子，那么更新当前元素的标记值为那个值

//       如果左边和上面没有，则认为是一个新的骰子，分配全局唯一标记，点数为0，存入map

// 3.‘X’其标记的操作更新操作月'*'是相同的，其实对于区分骰子的工作来说'X'和‘*’是一样的，他们都是骰子的一部分
//     不同的是'X'需要考虑'X'左边和上面存在'X'的情况

//     假如有个'X'说明这个点其实属于前面被遍历过的，不需要跟新相应骰子标号和点数对

//      如果左边上面没有'X'有'*'的话，那就是一个已登记的骰子中出现的新的点数，更新对应值加一，如果都是'*'，一个新的骰子并点数为1

//     还有就是与两个'X'相邻，那么可能需要合并两个点数，那么最后这个元素所属的骰子反而要自减1，当然如果是以下情况


//      X***............
//   XXX***...........
// XXXX**............
// 其中红色的在遍历到的时候，可能会认为要将对应的骰子的点数自减1，但是其实这个骰子上的点并不是在红色这个像素点合并的，而是在其左边的时候就已经可以合并 了。这个问题其实是因为分割点数和分割骰子是同样的问题，然而我却想在分割骰子的同时去分割点数。

// 最好的做法是去用相同的一个map来标记点，或者两遍处理。

// 然而我用了一个不健全的做法,如果遍历到i,j 并且i-1,j  和 i, j-1都是'X'，那么如果i-1,'j-1'是'X'的话，那么我就认为不需要自减一，因为我认为至少是在i,j-1之前(包括自己)做的第一次点数合并，但是如果出现

// XXX

// X*X

// XXX

// 的情况，那这种其实就出错了。但是想想一张照片中一个黑点中，如果中间有个像素是白的也是不太能吧，大概就是不会出现这种不连续的情况，我就用粗糙的判断了，当然也可以用递归深搜的方法去看左边和右边的点在已遍历的点中能否有连通的路径。也可以预处理，在分割骰子前，现分割点，对于有点的地方，一团'X'只用一个'X'表示就好了，就不用考虑这种情况了。

#include <iostream>
#include <vector>
#include <map>
#include <queue>
 
using namespace std;
int totalNum = 0;
int dotNum = 0;
class cmp {
    public: 
	bool operator()(int a, int b) {
		return a > b;
	}
};
void merge(char(*img)[55], int x, int y, int newNum, int oldNum) {
	if (img[x][y] - '0' != oldNum) {
		return;
	}
	img[x][y] = newNum + '0';
	if (x - 1 >= 0) {
		merge(img, x - 1, y, newNum, oldNum);
	}
	if (y - 1 >= 0) {
		merge(img, x, y - 1, newNum, oldNum);
	}
	return;
}
void handle(char (*raw)[55], char (*img)[55], int w, int h, map<int, int> & result) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (img[i][j] == '.') continue;
			if (img[i][j] == '*') {
				int preNum = -1;
				if (i - 1 >= 0) {
					if (img[i - 1][j] != '.') {
						preNum = img[i - 1][j] - '0';
					}
				}
				if (j - 1 >= 0) {
					if (img[i][j - 1] != '.') {
						if (preNum == -1) {
							preNum = img[i][j - 1] - '0';
						}
						if (preNum != -1 && preNum != img[i][j - 1] - '0') {
							//need merge
							int mergeNum = img[i][j - 1] - '0';
							merge(img, i, j - 1, preNum, mergeNum);
 							int dotNum = result.at(mergeNum);
							result[mergeNum] = -1;
							result[preNum] += dotNum;
						}
					}
				}
				// new dice
				if (preNum == -1) {
					img[i][j] = '0' + totalNum;
					result[totalNum] = 0;
					totalNum++;
				}
				else {
					img[i][j] = '0' + preNum;
				}
			}
			if (img[i][j] == 'X') {
				int preNum = -1;
				int connect_dot = 0;
				if (i - 1 >= 0) {
					if (img[i - 1][j] != '.') {
						preNum = img[i - 1][j] - '0';
						if (raw[i - 1][j] == 'X') {
							connect_dot++;
						}
					}
				}
				if (j - 1 >= 0) {
					if (img[i][j - 1] != '.') {
						if (raw[i][j - 1] == 'X') {
							connect_dot++;
						}
						if (preNum == -1) {
							preNum = img[i][j - 1] - '0';
						}
						if (preNum != -1 && preNum != img[i][j - 1] - '0') {
							//need merge
							int mergeNum = img[i][j - 1] - '0';
							merge(img, i, j - 1, preNum, mergeNum);
							int dotNum = result.at(mergeNum);
							result[mergeNum] = -1;
							result[preNum] += dotNum;
						}
					}
				}
				// new dice
				if (preNum == -1) {
					img[i][j] = '0' + totalNum;
					result[totalNum] = 1;
					totalNum++;
				}
				// update dot numbers;
				else {
					if (connect_dot == 0)
					{
						result[preNum] += 1;
					}
					else if (connect_dot == 2 && raw[i-1][j-1]!='X'){
						result[preNum] -= 1;
					}
					img[i][j] = '0' + preNum;
				}
			}
		}
	}
}
int main() {
	int w, h;
	int caseNum = 0;
	char img[55][55];
	char raw[55][55];
	cin >> w >> h;
	while (true) {
		caseNum++;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> img[i][j];
				raw[i][j] = img[i][j];
			}
		}
		map<int, int> result;
		priority_queue<int, vector<int>, cmp> dot_num;
		handle(raw, img, w, h, result);
		for (int i = 0; i < totalNum; i++) {
			if (result[i] != -1) {
				dot_num.push(result[i]);
			}
		}
		cout << "Throw " << caseNum<< endl;
		while (true) {
			cout << dot_num.top();
			dot_num.pop();
			if (dot_num.empty()) break;
			else cout << " ";
		}
		cin >> w >> h;
		totalNum = 0;
		cout << endl << endl;
		if (w == 0 && h == 0) break;
		//else cout << endl;
	}
	return 0;
}

// 广搜找连通分量（非background），对于每个在搜索中的连通分量同步搜索它的连通分量（X）（更确切来说是走到X则切换搜索X连通分量）
// 使用两个队列：dice队列（非background中非X的入此队），dot队列（X入此队），出队时优先dot队列
// 出队时优先dot队列：则若走到X则会先把X连通分量扩展完，而不会出现多次从非X到同一个X连通分量，方便计数

#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
string pic[MAXN];
int visited[MAXN][MAXN];
struct Pos
{
    int x;
    int y;
    Pos():x(-1),y(-1){}
    Pos(int x0,int y0):x(x0),y(y0){}
};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    int w,h;
    int cs=1;
    string no_use;
    while(cin>>w>>h && (w||h)){
        cout<<"Throw "<<cs<<endl;
        ++cs;
        getline(cin,no_use);
        for(int i=0; i<h; ++i){
            getline(cin,pic[i]);
            for(int j=0; j<w; ++j)visited[i][j]=0;
        }
        vector<int>re;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(pic[i][j]!='.' && visited[i][j]==0){
                    int dot_cnt=0;
                    //new comp
                    queue<Pos>q,dotq;
                    visited[i][j]=1;//mark when pushing
                    if(pic[i][j]=='X'){
                        ++dot_cnt;
                        dotq.push({i,j});
                    }
                    else q.push({i,j});
                    int x,y,newx,newy;
                    while(q.empty()==0 || dotq.empty()==0){
                        //dotq first
                        if(dotq.empty()==0){
                            x=dotq.front().x;
                            y=dotq.front().y;
                            dotq.pop();
                        }
                        else{
                            x=q.front().x;
                            y=q.front().y;
                            q.pop();
                        }
                        for(int i=0; i<4; ++i){
                            newx=x+dx[i];
                            newy=y+dy[i];
                            if(newx>=0&&newx<h&&newy>=0&&newy<w && visited[newx][newy]==0 && pic[newx][newy]!='.'){
                                visited[newx][newy]=1;
                                if(pic[newx][newy]=='X'){
                                    if(pic[x][y]!='X') ++dot_cnt;
                                    dotq.push({newx,newy});
                                }else q.push({newx,newy}); 
                            }
                        }
                    }
                    re.push_back(dot_cnt);
                }
            }
        }
        sort(re.begin(),re.end());
        for(int i=0;i<re.size(); ++i)cout<<re[i]<<" ";
        cout<<endl<<endl;
    }
    return 0;
}

//深搜不行，不知道为什么
// #include <bits/stdc++.h>
// using namespace std;
// int h,w;
// #define check(x,y) (x>=0&&x<h&&y>=0&&y<w)
// int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
// void dfs1(int x,int y,vector<vector<char>> &dice,vector<vector<int>> &vis,int tag,char tar){
//     for(int i=0;i<4;i++){
//         int xx=x+dx[i],yy=y+dy[i];
//         if(check(xx,yy)&&!vis[xx][yy]&&dice[xx][yy]==tar){
//             vis[xx][yy]=tag;
//             dfs1(xx,yy,dice,vis,tag,tar);
//         }
//     }
// }
// int main(){
//     freopen("res.txt","w",stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tag=1;
//     while(cin>>w>>h&&h){
//         vector<vector<char>> dice(h);
//         vector<vector<int>> vis(h);
//         for(int i=0;i<h;i++){
//             dice[i].resize(w);
//             vis[i].resize(w);
//         }
//         for(int i=0;i<h;i++)
//         for(int j=0;j<w;j++)cin>>dice[i][j];
//         int tag1=0;
//         for(int i=0;i<h;i++)
//         for(int j=0;j<w;j++){
//             if((dice[i][j]=='*')&&!vis[i][j]){
//                 vis[i][j]=(++tag1);
//                 dfs1(i,j,dice,vis,tag1,'*');
//             }
//         }
//         vector<int> ans(tag1+1);
//         for(int i=0;i<h;i++)
//         for(int j=0;j<w;j++){
//             if((dice[i][j]=='X')&&!vis[i][j]){
//                 int res=0;
//                 for(int k=0;k<4;k++){
//                     int xx=i+dx[k],yy=j+dy[k];
//                     if(check(xx,yy)&&dice[xx][yy]=='*'){
//                         res=vis[xx][yy];
//                         break;
//                     }
//                 }
//                 ans[res]++;
//                 dfs1(i,j,dice,vis,1,'X');
//             }
//         }
//         sort(ans.begin()+1,ans.end());
//         cout<<"Throw "<<(tag++)<<"\n";
//         for(int i=1;i<=tag1;i++)cout<<ans[i]<<" ";
//         cout<<"\n\n";
//     }
//     return 0;
// }