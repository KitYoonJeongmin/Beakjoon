#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int a[1000001];
int f[1000001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		s.push(n);
		++f[n];
	}

	stack<int> s2, result;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		if (s2.empty())
		{
			s2.push(temp);
			result.push(-1);
		}
		else
		{
			while (!s2.empty() && f[temp] >= f[s2.top()])
			{
				s2.pop();
			}
			if (s2.empty())
			{
				result.push(-1);
			}
			else
			{
				result.push(s2.top());
			}
			s2.push(temp);
		}
	}

	while (!result.empty())
	{
		cout << result.top() << ' ';
		result.pop();
	}

	return 0;
}