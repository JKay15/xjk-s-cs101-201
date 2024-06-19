#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;
int n;
vector<char> ans;
vector<char> stack;
const char cont[2] = {'(', ')'};
void dfs(int left, int right)
{
	if (left + right == 2 * n)
	{
		std::for_each(ans.begin(), ans.end(), [](char x)
					  { cout << x; });
		cout << endl;
		return ;
	}
	if (left < n)
	{
		ans.push_back(cont[0]);
		stack.push_back(cont[0]);
		dfs(left + 1, right);
		stack.pop_back();
		ans.pop_back();
	}
	if (right < n && stack.size() > 0)
	{
		stack.pop_back();
		ans.push_back(cont[1]);
		dfs(left,right+1);
		stack.push_back(cont[0]);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	dfs(0,0);

	return 0;
}