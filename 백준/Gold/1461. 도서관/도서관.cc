#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	vector<int> v;
	int N, M; cin >> N >> M;
	int minusNum = 0;
	for (int i = 0; i < N; i++)
	{
		int bookLoc; cin >> bookLoc;
		v.push_back(bookLoc);
		if (bookLoc < 0) minusNum++;
	}

	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = N - 1; i >= minusNum; i -= M)
	{
		answer += (v[i] * 2);
	}
	for (int i = 0; i < minusNum; i += M)
	{
		answer -= (v[i] * 2);
	}

	answer -= max(abs(v[0]), abs(v[N - 1]));

	cout << answer << "\n";


	return 0;
}