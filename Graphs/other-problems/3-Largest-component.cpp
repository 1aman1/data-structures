#include <iostream>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of list

2-> find size of largest component
*/

struct Graph
{
public:
	typedef int node;
	typedef std::list<node> graph_t;

protected:
	graph_t *_graph;
	node _vertices;

public:
	void
	print();

	void
	add_edge(int, int);

	Graph(int v) : _vertices(v)
	{
		_graph = new graph_t[_vertices];
	}

	~Graph()
	{
		delete[] _graph;
	}
};

void Graph::print()
{
	for (int each_node = 0; each_node < _vertices; ++each_node)
	{
		std::cout << "vertex : " << each_node << " : ";
		{
			std::cout << "[ ";

			for (auto neighbrs = _graph[each_node].begin(); neighbrs != _graph[each_node].end(); ++neighbrs)
			{
				std::cout << *neighbrs << ", ";
			}

			std::cout << " ]" << std::endl;
		}
	}
}

void Graph::add_edge(int u, int v)
{
	_graph[u].push_back(v);
}


class Solution : public Graph
{
	std::vector<bool> _visited;

public:
	Solution(int V) : Graph(V) { _visited.resize(V); };

	int get_largest_component();

	int get_component_size(int);
};

int Solution::get_component_size(int src)
{
	if (_visited[src])
		return 0;

	_visited[src] = true;

	int size = 1;
	for (auto neighbours = _graph[src].begin(); neighbours != _graph[src].end(); ++neighbours)
	{
		size += get_component_size(*neighbours);
	}

	return size;
}

int Solution::get_largest_component()
{
	int largest = 0;
	int size = 0;

	for (int nodes = 0; nodes < _vertices; ++nodes)
	{
		size = get_component_size(nodes);
		largest < size ? largest = size : largest;
	}

	return largest;
}

int main()
{
	Solution go(9);

	go.add_edge(0, 8);
	go.add_edge(0, 1);
	go.add_edge(0, 5);
	go.add_edge(2, 3);
	go.add_edge(2, 4);
	go.add_edge(3, 4);
	go.add_edge(5, 8);

	go.print();

	std::cout << go.get_largest_component() << "\n";

	return 0;
}