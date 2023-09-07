#include <iostream>
using namespace std;

#define MAX 1000001

int tree[MAX * 8];
int ans[MAX], arr[MAX];

int update(int c, int t, int s, int e, int value)
{
	if (t > e || t < s) return tree[c];
	if (s == e)
	{
		tree[c] = value;
		return tree[c];
	}
	int mid = (s + e) / 2;
	tree[c] = update(c * 2, t, s, mid, value) + update(c * 2 + 1, t, mid + 1, e, value);
	return tree[c];
}

int query(int c, int l, int r, int s, int e)
{
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[c];
	int mid = (s + e) / 2;
	return query(c * 2, l, r, s, mid) + query(c * 2 + 1, l, r, mid + 1, e);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
    while (T--) 
    {
        int n, m;
        cin >> n >> m;
        int size = n + m - 1;
        for (int i = 0; i < n + m; i++) 
        {
            if (i < n)
                update(1, i, 0, size, 1);
            else
                update(1, i, 0, size, 0);

        }
        for (int i = n; i >= 1; i--) 
        {
            arr[i] = (n - i);
        }

        for (int i = 0; i < m; i++) 
        {
            int data; cin >> data;
            int target = arr[data];
            ans[i] = query(1, target + 1, size, 0, size);
            update(1, target, 0, size, 0);
            update(1, n, 0, size, 1);
            arr[data] = n++;
        }

        for (int i = 0; i < m; i++) 
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

	return 0;
}


