#include <iostream>
#define MAX 246912
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	bool arr[MAX + 1] = { false };
	arr[1] = true;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (arr[i]) continue;
		for (int j = 2; i * j <= MAX; j++) arr[i * j] = true;
	}

	int N; cin >> N;
	while (N != 0)
	{
		int answer = 0;
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (arr[i]) continue;
			answer++;
		}
		cout << answer << "\n";
		cin >> N;
	}

	return 0;
}