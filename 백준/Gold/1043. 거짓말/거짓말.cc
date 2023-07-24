#include <iostream>
#include <vector>
using namespace std;


int parents[51];



int Find(int x) {
	if (parents[x] == x) return x;
	return x = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parents[x] = y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int peopleNum, partyNum;
	cin >> peopleNum >> partyNum;

	//사실을 아는사람
	int N; cin >> N;
	vector<int> v;
	while (N--)
	{
		int num; cin >> num;
		v.push_back(num);
	}
	
	//부모 초기화
	for (int i = 0; i < peopleNum; i++)
	{
		parents[i] = i;
	}


	//파티 입력
	vector<int> partys[51];
	for (int i = 0; i < partyNum; i++)
	{
		int p; cin >> p;

		int num, pre;
		for (int j = 0; j < p; j++)
		{
			if (j == 0)	//처음에는 입력만
			{
				cin >> num;
			}
			else
			{
				pre = num;
				cin >> num;
				Union(pre, num); //집합에 추가
			}
			partys[i].push_back(num);
		}
	}

	int result = partyNum;
	for (auto party : partys)
	{
		bool CanWhistle = true;
		for (auto person : party)
		{
			if (!CanWhistle) break;
			for (auto e : v)
			{
				if (Find(person) == Find(e))
				{
					CanWhistle = false;
					break;
				}
			}
		}

		if (!CanWhistle) --result; //거짓말 못하면 말할 수 있는 파티에서 제외
	}

	cout << result;

	return 0;
}