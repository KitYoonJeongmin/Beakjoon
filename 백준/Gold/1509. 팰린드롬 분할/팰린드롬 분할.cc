#include<iostream>
#include<string>

using namespace std;
bool PCheck[2501][2501];
int dp[2501];
int main()
{
	string s; cin >> s;
	s.insert(0, " ");
	//한개짜리 팰린드롬
	for (int i = 1; i <= s.length(); i++) { PCheck[i][i] = true; }
	//두개짜리 팰린드롬
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i + 1])
		{
			PCheck[i][i + 1] = true;
		}
	}
	//세개 이상 팰린드롬
	for (int i = 2; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			if (s[j] == s[i + j] && PCheck[j + 1][j + i - 1]) // 끝부분의 문자가똑같고 안에 내용도 같다면
			{
				PCheck[j][j + i] = true;
			}
				
		}
	}


	for (int i = 1; i < s.length(); i++)
	{
		dp[i] = 200000000;
		for (int j = 1; j <= i; j++)
		{
			if (PCheck[j][i])
				dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
	cout << dp[s.length() - 1];

	return 0;
}