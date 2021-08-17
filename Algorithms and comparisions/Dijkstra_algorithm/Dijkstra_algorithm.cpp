#include <bits/stdc++.h>
using namespace std;
int arr[10][10]={0};

class Graph
{   public:
    int V;
    int graph[10][10]={0};
    int distance[100];
    int heap[100]={false};
    public:
    Graph(int vertices)
    {
        V = vertices;
        for(int i=0;i<V;i++)
            distance[i] = 10000;
    }
    void copy()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                graph[i][j]=arr[i][j];
            }
        }
    }
    void printSolution()
    {
        cout<<"Vertex \tDistance from source"<<endl;
        for(int node=0;node<V;node++)
            cout<<node<<"\t"<<distance[node]<<endl;
    }
    int min_distance()
    {
        int min_1 = 10000 ;
        int min_index;
        for(int v=0;v<V;v++)
        {
            if(distance[v] < min_1 && heap[v] == 0)
            {
                min_1 = distance[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(int src)
    {
        distance[src] = 0;

        for(int count=0;count<V;count++)
        {
            int u = min_distance();
            heap[u] = true;

            for(int v=0;v<V;v++)
            {
                if((graph[u][v] > 0 && heap[v] == false) && (distance[v] >distance[u]+graph[u][v]))
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
        printSolution();
    }
};

int main()
{

    int vertice,edge;

    cin>>vertice>>edge;
    int node_1,node_2,weight;
    Graph g(vertice);
    for(int i=0;i<edge;i++)
    {
        cin>>node_1>>node_2>>weight;
        arr[node_1][node_2] = weight;
        arr[node_2][node_1] = weight;
    }
    g.copy();
    int s;
    cout<<"Enter the source: ";
    cin>>s;
    g.dijkstra(s);
    return 0;
}
