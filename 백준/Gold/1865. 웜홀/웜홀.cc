#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define INF 2e9

struct edge {
	int s, e, t;
};

long long dist[502];
vector<edge> edges;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--)
	{
		memset(dist, INF, sizeof(dist));
		edges.clear();
		int N, M, W; cin >> N >> M >> W; //지점의수, 도로의 개수, 웜홀의 개수
		int s, e, t;
		bool flag = false;

		for (int i = 0; i < M; i++)
		{
			cin >> s >> e >> t; // 연결된 지점의 번호, 이 도로를 통해 이동하는데 걸리는 시간
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> s >> e >> t; // 연결된 지점의 번호, 줄어드는 시간
			edges.push_back({ s,e,-t });
		}

		dist[1] = 0;

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < edges.size(); j++) { //모든 간선 탐색하여 최소 비용을 탐색함
				s = edges[j].s;
				e = edges[j].e;
				t = edges[j].t;
				if (dist[e] > dist[s] + t) {
					dist[e] = dist[s] + t;
				}
			}
		}
		for (int j = 0; j < edges.size(); j++) { //음의 사이클을 아지는지 탐색
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) { //위에서 최소비용을 모두 탐색했기 때문에 더이상 최소비용이 업데이트 된다는 것은 사이클을 의미
				flag = true;
				break;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}

	

	
	return 0;
}