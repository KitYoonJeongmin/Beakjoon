#include <iostream>
#include <string>
using namespace std;
string result;
string s1, s2;

bool BombCompare()
{
	if (result.length() < s2.length()) return false;

	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] != result[result.length() - s2.length() + i]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> s1 >> s2;
	result="";

	for (int i = 0; i < s1.length(); i++)
	{
		result += s1[i];
		if (BombCompare())
		{
			result.erase(result.end() - s2.length(), result.end());
		}
	}

	if (result.empty()) cout << "FRULA";
	else cout << result;

	return 0;
}