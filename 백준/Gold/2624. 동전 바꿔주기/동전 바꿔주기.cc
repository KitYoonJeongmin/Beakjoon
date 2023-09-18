#include <iostream>
using namespace std;
int p[101], n[101];
int dp[10001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int T,k; cin >> T >> k;
	for(int i=1; i<=k; i++)
	{
		cin >> p[i];
		cin >> n[i];
	}
	dp[0] =1;
	for(int i=1; i<=k; i++)
	{
		for (int j = T; j >= 1; j--) {
            int sum = 0;
            for (int k = 0; k < n[i]; k++) {
                sum += p[i];
                if (j - sum >= 0 && dp[j-sum] > 0) dp[j] += dp[j - sum];
            }
        }
	}
	cout << dp[T];
	return 0;
}