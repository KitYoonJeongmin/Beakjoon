#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; cin >> N;

	stack<pair<int, int>> s; //키, 연속으로 몇명인가
	long long result = 0;
	for (int i = 0; i < N; ++i)
	{
		int H; cin >> H;

		//지금 들어온애 키가 top보다 커서 뒤를 가림
		while (!s.empty() && H > s.top().first)
		{
			result += s.top().second;
			s.pop();
		}

		// 제일 앞에 있는 사람
		if (s.empty())
			s.push(make_pair(H, 1));
		else
		{
			if (s.top().first == H) //키가 같음
			{
				int c = s.top().second;
				s.pop();
				if (!s.empty()) ++result;

				result += c;
				s.push(make_pair(H, c+1));
			}
			else //키가 작음
			{
				++result;
				s.push(make_pair(H, 1));
			}
		}
	}
	cout << result;

	return 0;
}