#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, result=0;
bool alpha[30];
vector<string> v;
void dfs(int cnt, int index)
{
	if (cnt == K-5)
	{
		cnt = 0;
		for (auto s : v)
		{
			bool canRead = true;

			for (auto c : s)
			{
				int x = c - 'a';
				if (alpha[x]) continue;
				else canRead = false; break;
			}
			if (canRead) cnt++;
		}
		result = max(result, cnt);
		return;
	}
	for (int i = index; i < 26; i++)
	{
		if (alpha[i]) continue; 
		alpha[i] = true;
		dfs(cnt + 1, i+1);
		alpha[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> K;
	
	int n;
	n = 'a' - 'a';
	alpha[n] = true;
	n = 'n' - 'a';
	alpha[n] = true;
	n = 't' - 'a';
	alpha[n] = true;
	n = 'i' - 'a';
	alpha[n] = true;
	n = 'c' - 'a';
	alpha[n] = true;

	string s; //a c i t n 5개
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		s = s.substr(4, s.size() - 8);
		v.push_back(s);
	}
	dfs(0, 0);
	cout << result;
	return 0;
}