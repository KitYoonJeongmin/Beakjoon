#include <iostream>

using namespace std;
int N;
long long tree[100001];


long long sum(int i) // 누적 합을 계산하는 함수
{
	long long result = 0;
	while (i > 0)
	{
		result += tree[i];
		i -= (i & (-i)); //0이 아닌 마지막 비트만큼 빼가며 이동
	}
	return result;
}

void update(int i, int n, int size) // i번째 수에 n만큼 더하는 함수(size는 트리의 크기)
{
	while (i <= size)
	{
		tree[i] += n;
		i += (i & (-i));
	}
}

long long interval_sum(int s, int e)
{
	return sum(e) - sum(s);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	int pre, cur; cin >> pre;
	update(1, pre, N);

	for (int i = 2; i <= N; i++)
	{
		cin >> cur;
		update(i, cur-pre, N); // 2연산 시 구간합으로 k번째 수를 구할 수 있도록 이전 수를 빼주며 더해줌
		pre = cur;
	}

	int queryNum; cin >> queryNum;
	int n, i, j, x;
	long long k;
	while (queryNum--)
	{
		cin >> n;
		if (n == 1)
		{
			cin >> i >> j >> k;
			update(i, k, N); //i번째부터 끝까지 k를 더해줌
			update(j + 1, -k, N); // j+1번째 부터 k를 빼줌
									// 결과적으로 i~j까지 k를 더해주게 됨
		}
		else
		{
			cin >> x;
			cout << sum(x)<<'\n';
		}
	}
	

	return 0;
}