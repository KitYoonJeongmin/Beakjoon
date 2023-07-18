#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;

	while (T--)
	{
		bool isError = false;
		string funcs; cin >> funcs;
		int lenght; cin >> lenght;
		deque<int> dq;
		string s; cin >> s;
		int i = 1;
		while (s[i] != '\0') {
			int x = 0;
			while (s[i] >= '0' and s[i] <= '9') {
				x *= 10;
				x += int(s[i] - '0');
				i++;
			}
			if (x != 0) {
				dq.push_back(x);
			}
			i++;
		}


		bool pointerIsForward = true;
		for (auto func : funcs)
		{
			if (func == 'R')
			{
				pointerIsForward = !pointerIsForward;
			}
			else
			{
				if (lenght <= 0)
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}
				if (pointerIsForward) dq.pop_front();
				else dq.pop_back();
				--lenght;
			}
		}
		if (isError) continue;

		cout << '[';
		for (int i = 0; i < lenght; i++)
		{
			if (pointerIsForward)
			{
				cout << dq.front();
				dq.pop_front();
			}
			else
			{
				cout << dq.back();
				dq.pop_back();
			}

			if (i != lenght - 1) cout << ',';
		}
		cout << "]\n";
	}

	return 0;
}