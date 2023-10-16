#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int n;
bool func(int s, int e, int t)
{
	if (s > e) return false;
	
	int m = (s + e) / 2; 
	if (arr[m] == t) return true;
	if (t > arr[m])  return func(m + 1, e, t);
	else return func(s, m-1, t);
}
int main()
{
	long long x;
	while (cin >> x)
	{
		x *= 10000000;
		cin >> n; //num of lego
		
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);

		int low = 0, high = n - 1;
		bool find = false;
		while (low < high) 
		{

			int sum = arr[low] + arr[high];
			if (sum == x) 
			{
				find = true;
				break;
			}
			if (sum < x) low++;
			else high--;
		}

		if (find)
			cout << "yes " << arr[low] << ' ' << +arr[high] << endl;
		else
			cout << "danger" << endl;

	}

	return 0;
}