#include "libraries.h"

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

vector<int> graph[1001], graphC[1001];
int viz[1001], dist[1001];

int find_min(int dist[], int N, int viz[])
{
	int dist_min = INT_MAX, ii = -1;

	for (int i = 1; i <= N; i++)
		if (!viz[i] && dist_min > dist[i])
		{
			ii = i;
			dist_min = dist[i];
		}
	return ii;
}

int main()
{
	int N, M, x, y, cost;

	fin >> N >> M;

	for (int i = 2; i <= N; i++)
		dist[i] = INT_MAX;
	dist[1] = 0;

	for (int i = 0; i < M; i++)
	{
		fin >> x >> y >> cost;
		graph[x].push_back(y);
		graphC[x].push_back(cost);
	}

	for (int i = 1; i <= N; i++)
	{
		int xmin = find_min(dist, N, viz);
		viz[xmin] = 1;
		for (int j = 0; j < graph[xmin].size(); j++)
			if (dist[xmin] + graphC[xmin][j] < dist[graph[xmin][j]])
				dist[graph[xmin][j]] = dist[xmin] + graphC[xmin][j];
	}

	for (int i = 2; i <= N; i++)
		if (dist[i]==INT_MAX)
			fout << 0 << ' ';
		else
			fout << dist[i] << ' ';
	system("pause");
}
