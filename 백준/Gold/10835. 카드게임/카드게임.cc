#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int L[2001], R[2001];
int DP[2001][2001];
int DFS(int l, int r)
{
	if (l > N || r > N) return 0;
	if (DP[l][r] != -1) return DP[l][r];

	DP[l][r] = 0;
	DP[l][r] = max(DFS(l + 1, r + 1), DFS(l + 1, r)); //양쪽 다 버리거나 한쪽만 버리는 경우
	if (L[l] > R[r]) DP[l][r] = max(DP[l][r], DFS(l, r + 1) + R[r]);

	return DP[l][r];
}

int main()
{
	ios::sync_with_stdio(false);
	//delete l, l+r
	//l>r -> delte r : get r score

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> R[i];

	memset(DP, -1, sizeof(DP));
	cout << DFS(1, 1);
	return 0;
}