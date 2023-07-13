#include <iostream>

using namespace std;

int main()
{
	long long dp[31][31];

	for (int i = 0; i <= 30; i++)
		dp[0][i] = 1;

	for (int w = 1; w <= 30; w++) {
		for (int h = 0; h <= 30; h++) {
			if (h == 0)
				dp[w][h] = dp[w - 1][1]; //한개짜리 반개 먹어서 반개가 하나 생김
			else
				dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1];  //한개짜리 먹는 경우+ 반개짜리 먹는 경우
		}
	}

	while (true)
	{
		int N; cin >> N;
		
		if (N == 0)
			break;

		cout << dp[N][0] << '\n';
	}

	return 0;
}