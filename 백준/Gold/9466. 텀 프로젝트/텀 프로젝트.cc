#include <iostream>
#include <cstring>
using namespace std;

bool visited[100001], finish[100001];
int result, arr[100001];
void dfs(int cur)
{
	visited[cur] = true;
	int next = arr[cur];

	if (!visited[next]) dfs(next);
	else if(!finish[next])
	{
		for (int i = next; i != cur; i = arr[i]) result++;
		result++;
		

	}
	finish[cur] = true;

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	int N;
	while (T--)
	{
		result = 0;
		memset(visited, false, sizeof(visited));
		memset(finish, false, sizeof(finish));
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= N; i++) {
			if(!visited[i]) dfs(i);
			
		}

		cout << N - result<<'\n';
	}

	return 0;
}