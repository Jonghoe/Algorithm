#include <iostream>
#include <algorithm>
#include <vector>

class unionfind
{
public:
	unionfind(int const n) : _parent(n + 1, 0), _rank(n + 1, 1)
	{
		for (auto i = 1; i <= n; ++i) _parent[i] = i;
	}
	~unionfind() {}

	int find(int v)
	{
		return (_parent[v] == v) ? v : _parent[v] = find(_parent[v]);
	}

	void unite(int v, int u)
	{
		v = find(v);
		u = find(u);

		_parent[v] = u;
	}

private:
	std::vector<int> _parent;
	std::vector<int> _rank;
};

struct Edge
{
	int start, end;
	int cost;

	Edge() {};
	Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {};
	~Edge() {};

	bool operator<(Edge const& edge) const { return edge.cost > cost; }
};

int N, M;

int main(int const argc, char const** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N >> M;

	unionfind p(N);
	std::vector<Edge> adj(M);

	for (auto i = 0; i < M; ++i)
	{
		std::cin >> adj[i].start >> adj[i].end >> adj[i].cost;
	}

	std::sort(std::begin(adj), std::end(adj));

	int answer = 0;
	for (auto i = 0; i < M; ++i)
	{
		Edge edge = adj[i];

		int x = p.find(edge.start);
		int y = p.find(edge.end);

		if (x != y)
		{
			p.unite(edge.start, edge.end);

			answer += edge.cost;
		}
	}

	std::cout << answer << "\n";

	return 0;
}