#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll arr[1000001];
ll tree[1000001 * 4];
ll query(int c, int s, int e, int k)
{
	if (s == e) return e;

	int mid = (s + e) / 2;
	if (tree[c * 2] >= k) return query(c * 2, s, mid, k); //앞부분 탐색
	else return query(c * 2 + 1, mid + 1, e, k - tree[c*2]); // 뒷부분 탐색
}

void update(int c, int s, int e, int index, ll value)
{
	if (index < s || index > e) return; //바운드
	if (s == e) // 갱신
	{
		tree[c] = value; return;
	}
	//탐색및 이전값 갱신
	int mid = (s + e) / 2;
	update(c * 2, s, mid, index, value);
	update(c * 2 + 1, mid+1, e, index, value);
	tree[c] = tree[c * 2] + tree[c * 2 + 1];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	ll A, B, C;

	while (N--)
	{
		cin >> A;
		if (A == 1) // 꺼내기
		{
			cin >> B;
			int temp = query(1, 1, 1000001, B);
			cout << temp << '\n';
			update(1, 1, 1000001, temp, arr[temp] - 1); //하나 빼기
			--arr[temp];
		}
		else // 넣기
		{
			cin >> B >> C;
			update(1, 1, 1000001, B, arr[B] + C);
			arr[B] += C;
		}
	}

	return 0;
}