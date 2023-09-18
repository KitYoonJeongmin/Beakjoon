#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int arr[3001], N;
ll dp[3001], pref[3001];

ll memo(int cur)
{
	if(cur > N) return 0;
	if(dp[cur] != -1e9) return dp[cur];
	dp[cur] = 0;
	ll tmp = 1e9;
	
	for(int i=cur; i<= N; i++)
	{
		tmp = min(tmp, pref[i] - pref[cur-1] - memo(i+1));
	}
	return dp[cur] = tmp;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int M = 3;
	while(M--)
	{
		int a[2] = {0};
		for(int i=N; i>0; i--) cin >> arr[i];
		for(int i=1; i<=N; i++) pref[i]  = pref[i-1] + arr[i];// i번째 까지 더한 값
		
		fill(dp, dp + 3001, -1e9);
		
		ll res = memo(1);
		//cout << res <<'\n';
		if(res> 0) cout << 'B' << '\n';
		else if(res < 0) cout << 'A' << '\n';
		else cout << 'D' << '\n';
	}
	
	return 0;
}
