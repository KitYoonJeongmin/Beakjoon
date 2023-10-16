#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> SegmentTree;
ll arr[2000001];
ll CreateSegmentTree(int s, int e, int n)
{
    if (s == e) return SegmentTree[n] = arr[s];
    ll left = CreateSegmentTree(s, (s + e) / 2, n * 2);
    ll right = CreateSegmentTree((s + e) / 2 + 1, e, n * 2 + 1);
    SegmentTree[n] = left + right;
    return SegmentTree[n];
}
void UpdateSegmentTree(int s, int e, int n, int index, int diff)
{
    if (index < s || index > e) return;
    SegmentTree[n] += diff;
    if (s < e)
    {
        UpdateSegmentTree(s, (s + e) / 2, n * 2, index, diff);
        UpdateSegmentTree((s + e) / 2 + 1, e, n * 2 + 1, index, diff);
    }
}
ll SumOfSegmentTree(int s, int e, int n, int l, int r)
{
    if (l > e || r < s) return 0;
    if (l <= s && r >= e) return SegmentTree[n];
    ll left = SumOfSegmentTree(s, (s + e) / 2, n * 2, l, r);
    ll right = SumOfSegmentTree((s + e) / 2 + 1, e, n * 2 + 1, l, r);
    return left + right;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    
    int TreeHeight = (int)ceil(log2(N));
    int TreeSize = (1 << (TreeHeight + 1));
    SegmentTree.resize(TreeSize);
    
    while (M--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        if (i == 0)
        {
            if (j > k)
            {
                int temp = k; k = j; j = temp;
            }
            cout << SumOfSegmentTree(1, N , 1, j, k)<<"\n";
        }
        else
        {
            int t = k - arr[j];
            arr[j] = k;
            UpdateSegmentTree(1, N , 1, j, t);
        }
    }
    return 0;
}