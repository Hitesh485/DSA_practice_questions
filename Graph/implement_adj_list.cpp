#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// To make graph generic... int, char, string...
template <typename T>

class Graph{
    public:
    unordered_map<T, list<T>> adjList;
    // unordered_map<int, list<int>> adjList;
    // weight include in list
    // unordered_map<int, list<pair<int, int>> > adjList;

    void  addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adjList[u].push_back(v);

        if (direction == 0)
        {
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }


    void  addEdgeWithWeight(int u, int v, int weight, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adjList[u].push_back(v);
        // adjList[u].push_back({v, weight});

        if (direction == 0)
        {
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        cout << endl;
        for (auto node: adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
                // for weighted graph -------------->
                // cout << "("  << neighbour.first << " , " << neighbour.second <<")";
            }
            cout << endl;
        }
    }
};

int main ()
{

    // Graph g;
    Graph<char> g;

    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);


    // undirected input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.print();

    // directed input
    // g.addEdge(0,1,1);
    // g.addEdge(1,0,1);
    // g.addEdge(0,2,1);
    // g.addEdge(2,0,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,1,1);


    // directed weighted graph
    // g.addEdgeWithWeight(0,1,5,0);
    // g.addEdgeWithWeight(0,2,3,0);
    // g.addEdgeWithWeight(1,2,6,0);
    g.print();


    return 0;
}