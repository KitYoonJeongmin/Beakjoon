#include<iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;


int N, M;
vector<int> arr;
vector<int> segmentTree;
vector<pair<int, int>> cmd;


int MakeSegTree(int node, int s, int e)
{
	if (s == e) //원소가 하나일 때
	{
		segmentTree[node] = arr[s];
	}
	else
	{
		int mid = (s + e) / 2;
		int lTree = MakeSegTree(node * 2, s, mid);
		int rTree = MakeSegTree(node * 2 + 1, mid + 1, e);
		segmentTree[node] = min(lTree, rTree);
	}
	return segmentTree[node];
}

int Query(int node, int s, int e, int l, int r)
{
	if (r<s || l>e) return 2e9; //바운드 처리
	if (l <= s && e <= r) return segmentTree[node]; //원하는 값을 찾아 넘김

	int mid = (s + e) / 2;
	int lTree = Query(node * 2, s, mid, l, r);
	int rTree = Query(node * 2 + 1, mid + 1, e, l, r);
	return min(lTree, rTree);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N>>M;

	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		cmd.push_back(make_pair(a, b));
	}

	int height = ceil(log2(N));
	int size = (1 << (height + 1));
	segmentTree.resize(size);

	MakeSegTree(1, 0, N - 1);
	for (int i = 0; i < cmd.size(); i++)
	{
		int index1 = cmd[i].first - 1;
		int index2 = cmd[i].second - 1;

		cout << Query(1, 0, N - 1, index1, index2) << '\n';
	}
	return 0;
}