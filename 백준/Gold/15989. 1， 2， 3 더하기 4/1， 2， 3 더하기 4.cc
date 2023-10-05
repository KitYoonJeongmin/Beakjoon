#include <iostream>
#define MAX 10001
using namespace std;
int DP[MAX][4];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;


	DP[0][1] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		if (i >= 3)
			DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}
	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		cout << DP[num][1] + DP[num][2] + DP[num][3] <<'\n';
	}
	return 0;
}