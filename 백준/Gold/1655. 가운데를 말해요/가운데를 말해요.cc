#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	priority_queue<int> pq1;//top이 큰거
	priority_queue<int, vector<int>, greater<int>> pq2; //top이 작은거
	vector<int> result;

	for (int i = 1; i <= N; i++)
	{
		int n; cin >> n;
		if (pq1.empty() || pq1.top() > n)	//비어있거나 가장 작은것 보다 작으면
		{
			pq1.push(n);
			while (!pq1.empty()&& pq1.size() > (int)((float)i / (float)2 + 0.5f))	//절반이 되도록 조정
			{
				pq2.push(pq1.top());
				pq1.pop();
			}
			
		}
		else
		{
			pq2.push(n);
			while (!pq2.empty()&& pq2.size() > i / 2)	//절반이 되도록 조정
			{
				pq1.push(pq2.top());
				pq2.pop();
			}
			
		}

		result.push_back(pq1.top());

	}
	for (int r : result)
	{
		cout << r << "\n";
	}
	return 0;
}