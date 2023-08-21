#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<int> v[51];
set<int> deleteNodes;
void dfs(int s)
{
	deleteNodes.insert(s);
	if(v[s].empty()) return;
	for(int next: v[s])
	{
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int n; cin >> n;
		if(n == -1) continue;
		v[n].push_back(i);
	}
	int M; cin >> M;
	dfs(M);
	
	int result = 0;
	for(int i=0; i<N; i++)
	{
		if(v[i].empty() && deleteNodes.find(i) == deleteNodes.end())
		{
			result++;
		}
		else if(v[i].size() == 1 && v[i][0] == M)
		{
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}