#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

bool viz[200005];
vector <pair<int, int>> adj[200005];
vector <tuple<int, int, int >> muchii;

long long prim(int x)
{
	priority_queue<tuple<int, int, int >,vector<tuple<int, int, int >>,greater<tuple<int, int, int >> > heap;
	int y;
	long long Cost = 0;
	tuple<int, int, int >  tuplu;
	heap.push(make_tuple(0, x, x));
	while (!heap.empty())
	{
		// Select the edge with minimum weight
		tuplu = heap.top();
		heap.pop();
		x = get<1>(tuplu);
		y = get<2>(tuplu);
		// Checking for cycle
		if (viz[x] == true)
			continue;
		Cost += get<0>(tuplu);
		if (x != y)
			muchii.push_back(make_tuple(get<0>(tuplu), x, y));
		viz[x] = true;
		for (int i = 0; i < adj[x].size(); i++)
		{
			y = adj[x][i].second;
			if (viz[y] == false)
				heap.push(make_tuple(adj[x][i].first, y, x));
		}
	}
	return Cost;
}

int main()
{
	ifstream f("apm.in");
	ofstream g("apm.out");
	int i, N, M, x, y, c;

	f >> N >> M;
	for (i = 1; i <= M; i++)
	{
		f >> x >> y >> c;
		adj[x].push_back(make_pair(c, y));
		adj[y].push_back(make_pair(c, x));
	}
	// Selecting 1 as the starting node
	g << prim(1) << "\n";
	int lim = muchii.size();
	g << lim << "\n";
	for (i = 0; i < lim; i++)
		g << get<1>(muchii[i]) << " " << get<2>(muchii[i]) << "\n";
	return 0;
}
