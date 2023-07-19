#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


stack<int> s;
int ans[1000001];
int seq[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; i >= 0; i--) //역순으로 탐색
	{
		while (!s.empty() && s.top() <= seq[i])
			s.pop();

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(seq[i]); //가장 오른쪽에 있는걸 넣어줌
	}

	// 정답 출력
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}