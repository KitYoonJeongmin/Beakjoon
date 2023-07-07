#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> chu;
bool dp[31][15001];
int N, M;

void solve(int i, int w)
{
	if (i > N || dp[i][w]) { return; }
	dp[i][w] = true;
	solve(i + 1, w + chu[i]);
	solve(i + 1, abs(w - chu[i]));
	solve(i + 1, w);
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int weight;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> weight;
		chu.push_back(weight);
	}
	chu.push_back(0);
	solve(0, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> weight;
		if (weight > 15000) 
			cout << "N ";
		else if (dp[N][weight])
			cout << "Y ";
		else
			cout << "N ";
	}
    return 0;
}