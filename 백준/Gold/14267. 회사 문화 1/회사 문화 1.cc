#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> p[100001];
int answer[100001];
int info[100001];
void func(int p_index, int w)
{
	if (w == 0) return;
	answer[p_index] += w;
	for (auto person : p[p_index])
	{
		func(person, w);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int chef; cin >> chef;
		if (chef == -1) continue;
		p[chef].push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		int p_index, w; cin >> p_index >> w;
		info[p_index] += w;
	}
	for (int i = 1; i <= N; i++)
	{
		func(i, info[i]);
	}
	
	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}