#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> arr[6];
int main()
{
	ios::sync_with_stdio(false);

	long long N; cin >> N;
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	long long answer = 0;

	//1일 때 예외 처리
	if (N == 1)
	{
		int m = 0;
		for (int i = 0; i < 6; i++)
		{
			answer += arr[i].first;
			m = max(m, arr[i].first);
		}
		answer -= m; 
		cout << answer;
		return 0;
	} 


	//모서리 부분
	int corner = 2e9;

	corner = min(corner, arr[0].first + arr[1].first + arr[2].first);
	corner = min(corner, arr[0].first + arr[2].first + arr[4].first);
	corner = min(corner, arr[0].first + arr[1].first + arr[3].first);
	corner = min(corner, arr[0].first + arr[3].first + arr[4].first);

	corner = min(corner, arr[5].first + arr[1].first + arr[2].first);
	corner = min(corner, arr[5].first + arr[2].first + arr[4].first);
	corner = min(corner, arr[5].first + arr[1].first + arr[3].first);
	corner = min(corner, arr[5].first + arr[3].first + arr[4].first);

	sort(arr, arr + 6);
	//가장자리 부분
	long long edge = 0;
	if (arr[0].second + arr[1].second == 5)
	{
		edge = arr[0].first + arr[2].first;
	}
	else 
	{ 
		edge = arr[0].first + arr[1].first;
	}

	long long plane = arr[0].first;

	answer += corner * 4;
	answer += (N - 2) * (N - 1) * 4 * plane;
	answer += (N - 2) * (N - 2) * plane;
	answer += (N - 2) * 4 * edge;
	answer += (N - 1) * 4 * edge;
	cout << answer;
	return 0;
}