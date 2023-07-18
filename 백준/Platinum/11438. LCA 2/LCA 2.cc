#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> vec(1000001);
vector<int> depthVec(100001, 0);
vector<vector<int>> parents(100001, vector<int>(17, 0));

void FindDepth(int num)
{
    for (auto i : vec[num])
    {
        if (depthVec[i] == 0)
        {
            depthVec[i] = depthVec[num] + 1;
            parents[i][0] = num;

            for (int j = 0; j < 16; j++)
            {
                parents[i][j + 1] = parents[parents[i][j]][j];

                if (parents[i][j + 1] == 0) //한도가 넘어가거나 없다면 종료
                    break;
            }
            FindDepth(i);
        }
    }
}

int FindLCA(int a, int b)
{
    if (depthVec[a] < depthVec[b]) swap(a, b);
    int diff = depthVec[a] - depthVec[b];
    int j = 0;

    while (diff)
    {
        if (diff % 2) a = parents[a][j];
        ++j;
        diff /= 2;
    }

    if (a != b)
    {
        for (int j = 16; j >= 0; --j)
        {
            if (parents[a][j] != parents[b][j])
            {
                a = parents[a][j];
                b = parents[b][j];
            }
        }
        a = parents[a][0];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    parents[1][0] = 1;
    depthVec[0] = 0;
    depthVec[1] = 1;

    int N; cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }
    FindDepth(1);

    int F; cin >> F;
    for (int i = 0; i < F; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << FindLCA(a, b) << '\n';
    }

    return 0;
}


