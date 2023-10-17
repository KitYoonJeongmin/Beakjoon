#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	int A[51][51], B[51][51];
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < M; j++)
		{
			A[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < M; j++)
		{
			B[i][j] = s[j] - '0';
		}
	}

	int answer = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (A[i][j] == B[i][j]) continue;
			for (int k = i; k <= i + 2; k++)
			{
				for (int l = j; l <= j + 2; l++)
				{
					A[k][l] = 1-A[k][l];
				}
			}
			
			answer++;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}