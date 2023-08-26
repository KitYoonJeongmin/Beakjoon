#include <iostream>

using namespace std;
int N, a[5000001], b[5000001];
int tree[5000001]; //펜윅트리 계산한 배열
int check[5000001]; //일련번호의 값이 2번째 배열에 나오는 순서 미리 저장

int sum(int i)
{
	int result = 0;
	while (i > 0)
	{
		result += tree[i];
		i -= (i & (-i));
	}
	return result;
}

void update(int i, int n, int size)
{
	while (i <= size)
	{
		tree[i] += 1;
		i += (i & (-i));
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	long long result = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		check[a[i]] = i; //a를 기준으로 b에 같은 수가 있는 순서 저장
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> b[i];
		result += (long long)sum(N) - (long long)sum(check[b[i]]);
		update(check[b[i]], i, N);
	}
	cout << result;

	return 0;
}