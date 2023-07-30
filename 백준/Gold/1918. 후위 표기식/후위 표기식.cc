#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	stack<char> cStack;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'z')
		{
			cout << s[i];
			continue;
		}
		if (s[i] == '(') cStack.push(s[i]);
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!cStack.empty() && (cStack.top() == '*' || cStack.top() == '/'))
			{
				cout << cStack.top();
				cStack.pop();
			}
			cStack.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!cStack.empty() && (cStack.top() != '('))
			{
				cout << cStack.top();
				cStack.pop();
			}
			cStack.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!cStack.empty() && (cStack.top() != '('))
			{
				cout << cStack.top();
				cStack.pop();
			}
			cStack.pop();
		}
	}
	while (!cStack.empty())
	{
		cout << cStack.top();
		cStack.pop();
	}

	return 0;
}