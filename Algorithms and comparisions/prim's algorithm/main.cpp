#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


typedef pair<int, int> iPair;

class Graph
{
	int V;

	list< pair<int, int> > *adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void primMST();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
void Graph::primMST()
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src = 0;
	vector<int> key(V, INF);
	vector<int> parent(V, -1);
	vector<bool> inMST(V, false);
	pq.push(make_pair(0, src));
	key[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(inMST[u] == true){
			continue;
		}

		inMST[u] = true;
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (inMST[v] == false && key[v] > weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	cout<<"Minimum spanning tree:"<<endl;
    cout<<"Parent \t node"<<endl;
	for (int i = 1; i < V; ++i)
		printf("%d \t %d\n", parent[i], i);
}

int main()
{

	int v,e;
	cout<<"Enter vertices and edges: ";
	cin>>v>>e;
	Graph g(v);

    int u1,v1,w;

    for(int i=0;i<e;i++)
    {
        cin>>u1>>v1>>w;
        g.addEdge(u1, v1, w);
    }


	g.primMST();

	return 0;
}
