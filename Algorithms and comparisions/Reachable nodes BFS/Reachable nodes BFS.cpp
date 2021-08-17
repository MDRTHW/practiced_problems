#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
	int V;
	list<int> *adj;

	Graph(int );

	void addEdge(int, int);

	vector<int> BFS(int, int, int []);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

vector<int> Graph::BFS(int componentNum, int src,int visited[])
{

	queue<int> queue;

	queue.push(src);

	visited[src] = componentNum;


	vector<int> reachableNodes;

	while(!queue.empty())
	{

		int u = queue.front();
		queue.pop();

		reachableNodes.push_back(u);


		for (auto itr = adj[u].begin();itr != adj[u].end(); itr++)
		{
			if (!visited[*itr])
			{

				visited[*itr] = componentNum;
				queue.push(*itr);
			}
		}
	}
	return reachableNodes;
}

void display_Nodes(int n,unordered_map <int, vector<int> > m)
{
	vector<int> temp = m[n];
	for (int i=1; i<temp.size(); i++)
		cout << temp[i] << " ";

	cout << endl;
}

void Reachable_Nodes(Graph g,int u)
{

	int V = g.V;
	int visited[V+1];
	memset(visited, 0, sizeof(visited));
	unordered_map <int, vector<int> > m;
	int componentNum = 0;



		if (!visited[u])
		{
			componentNum++;
			m[visited[u]] = g.BFS(componentNum, u, visited);
		}
		cout << "Reachable Nodes from " << u <<" are\n";
		display_Nodes(visited[u], m);

}


int main()
{

	int V;
	cout<<"Enter the number of vertices:";
	cin>>V;
	Graph g(V);
	cout<<"Enter graph data in matrix form(if connected 1, not connected 0):"<<endl;
	int inp,adj_mat[V][V];
	for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            cin>>inp;
            adj_mat[i][j]=inp;
        }
    }
	///connecting with edges
	for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(adj_mat[i][j]==1)
                g.addEdge(i, j);
        }
    }




    int s;
    cout<<"Enter the starting vertex :";
    cin>>s;

	Reachable_Nodes(g, s);

	return 0;
}
