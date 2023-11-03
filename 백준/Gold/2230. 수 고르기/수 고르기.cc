#include<iostream> 
#include<algorithm>
using namespace std;
int ar[100010];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	sort(ar, ar + n);
	int start = 0, end = 1;
	int dis, ans = 2e9;
	while (start < n)
	{
		dis = ar[end] - ar[start];
		if (dis < m)
		{
			end++;
			continue;
		}
		else if (dis == m)
		{
			ans = dis;
			break;
		}
		start++;
		ans = min(ans, dis);
	}
	cout << ans;
	return 0;
}