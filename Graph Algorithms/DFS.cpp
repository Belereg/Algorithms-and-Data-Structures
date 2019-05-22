#include"libraries.h"

ifstream fin("dfs.in");
ofstream fout("dfs.out");

vector <int> graph[10001];
int viz[10001];

void dfs(int source)
{
	viz[source] = 1;
	int Size = graph[source].size();
  
	for (int i = 0; i < Size; i++)
		if (!viz[graph[source][i]])
			dfs(graph[source][i]);
	
}

int main()
{
	int N, M, x, y, comp = 0;

	fin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		fin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
	{
		if (viz[i] == 0)
		{
			dfs(i);
			comp++;
		}
	}
	fout << comp;
}
