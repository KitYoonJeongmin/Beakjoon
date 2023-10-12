#include <iostream>

using namespace std;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	bool isMinus = false;
	bool isEven = false;
	if (n < 0)
	{
		isMinus = true;
		n *= -1;
	}
	if (n % 2 == 0) isEven = true;


	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2])%1000000000;
	}


	if (n == 0)
	{
		cout << '0' << '\n' << '0';
	}
	else if (!isMinus)
	{
		cout << 1 << '\n' << dp[n];
	}
	else
	{
		
		if (isEven) cout << -1 << '\n';
		else cout << 1 << '\n';
		cout << dp[n];
	}
	

	return 0;
}