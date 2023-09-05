#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
pair<ll, ll> arr[500005];
ll tree[500005 * 4];
ll query(int c, int s, int e, int qs)
{
	if (e < qs || N-1 < s) return 0; //바운드 처리
	if (qs <= s && e <= N-1) return tree[c]; 
	ll mid = (s + e) >> 1;
	ll left = query(2 * c, s, mid, qs);
	ll right = query(2 * c + 1, mid + 1, e, qs);
	return left + right;
}

void update(int c, int s, int e, int idx) {
	if (s == e) { tree[c] = 1; return; }

	int mid = (s + e) / 2;
	if (idx <= mid) update(2 * c, s, mid, idx);
	else update(2 * c + 1, mid + 1, e, idx);

	tree[c] = tree[2 * c] + tree[2 * c + 1];
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		arr[i] = { n,i }; //입력 수, index
	}

	sort(arr, arr + N);

	ll result = 0;
	for (int i = 0; i < N; i++)
	{
		int index = arr[i].second;
		result += query(1, 0, N - 1, index + 1); 
		update(1, 0, N - 1, index);
	}
	cout << result;
	return 0;
}