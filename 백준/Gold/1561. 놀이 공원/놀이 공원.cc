#include <iostream>

using namespace std;
long long N, M;
int arr[10001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	long long s, e, t, cnt, result = 1;
	for (int i = 0; i <M; i++) cin >> arr[i];
	if (N <= M) 
	{
		cout << N;
		return 0;
	}
	s = 1; e = (long long)30 * N;
	while (s <= e) 
	{
		t = (s + e) / 2;
		cnt = 0;
		for (int i = 0; i < M; i++) 
		{
			cnt += t / arr[i] + 1;
		}
		if (cnt >= N) //t일때 탄 사람이 N보다 많다면 왼쪽을 탐색
		{
			result = t;
			e = t - 1;
		}
		else s = t + 1;
	}

	cnt = 0;
	for (int i = 0; i < M; i++) //구한 시간에 태울 수 있는 총 사람수 구함
	{
		cnt += (result - 1) / arr[i] + 1;
	}
	for (int i = 0; i < M; i++) 
	{
		if (result % arr[i] == 0) cnt++;
		if (cnt == N) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}