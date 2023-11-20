#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[500001];
int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);
	vector<int> v(4);
	
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	sum = sum / (double)N;
	sum > 0 ? sum += 0.5 : sum -= 0.5;
	v[0] = sum;
	v[1] = arr[N / 2];
	v[3] = arr[N - 1] - arr[0];
	
	auto l = lower_bound(arr, arr + N, arr[0]);
	auto r = upper_bound(arr, arr + N, arr[0]);

	bool check_second = false;
	int cur = 0, max_size = 0;
	while (l != arr + N)
	{
		int count_size = r - l;
		if (max_size < count_size)
		{
			max_size = count_size;
			v[2] = *l;
			check_second = true;
		}
		else if (max_size == count_size && check_second)
		{
			v[2] = *l;
			check_second = false;
		}

		l = r;
		r = upper_bound(arr, arr + N, *l);
	}

	for (auto answer : v)
	{
		cout << answer << "\n";
	}

	return 0;
}