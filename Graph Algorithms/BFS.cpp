#include "libraries.h"

ifstream fin("bfs.in");
ofstream fout("bfs.out");

queue <int> myq;
vector <int> graph[100001];
int dist[100001], viz[100001];

void BFS(int source)
{
	viz[source] = 1;
	dist[source] = 0;
	myq.push(source);
	
	while (!myq.empty())
	{
		int x = myq.front();
		myq.pop();
		
		for (int i = 0; i < graph[x].size(); i++)
		{
			int vecin = graph[x][i];
			if (!viz[vecin])
			{
				viz[vecin] = 1;
				dist[vecin] = dist[x] + 1;
				myq.push(vecin);
			}
		}
	}

}

int main()
{
	int N, M, source, x, y;
	
	fin >> N >> M >> source;
	for (int i = 0; i < M; i++)
	{
		fin >> x >> y;
		graph[x].push_back(y);
	}
	BFS(source);
	for (int i = 1; i <= N; i++)
	{
		if (!viz[i])
			fout << -1 << ' ';
		else
			fout << dist[i] << ' ';
	}
	system("pause");
}
