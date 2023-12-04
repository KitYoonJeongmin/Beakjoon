#include<string>
#include<vector>
#include<iostream>

using namespace std;

vector<string> v;

void func(int n, int y, int x)
{
	char c = v[y][x];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (v[i][j] != c) {
				cout << '(';
				func(n / 2, y, x);
				func(n / 2, y, x+ n / 2);
				func(n / 2, y+ n / 2, x);
				func(n / 2, y+ n / 2, x+ n / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N,n;
	cin >> N;
	n = N;
	while (n--)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	func(N, 0, 0);

	return 0;
}