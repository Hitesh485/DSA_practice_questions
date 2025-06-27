#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        cout << endl;
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << " , ";
            }
            cout << endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;
        // unordered_map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            // A
            T frontNode = q.front();
            // B
            q.pop();
            // C
            cout << frontNode << " , ";
            // D -> insert neighbours
            for (auto neighbours : adjList[frontNode])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,6,0);
    // g.addEdge(7,4,0);

    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    g.print();

    int n = 5; // number of nodes

    cout << "BFS --------------> " << endl;
    // g.bfs(0); // 0  as a source node.

    // Good practice to take disconnected graph by default.
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    // DFS ->
    cout << "DFS -----------------------> " << endl;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }
    cout << endl;
    return 0;
}



/* DFS with weighted and not weighted */
/*
#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<pair<int, int>> > adjList_W;

    void addEdge(int u, int v, bool dir)
    {
        adjList[u].push_back(v);
        if (dir == 0)
        {
            adjList[v].push_back(u);
        }
    }
    void addEdgeWithWeight(int u, int v, int weight, bool dir)
    {
        adjList_W[u].push_back({v, weight});
        if (dir == 0)
        {
            adjList_W[v].push_back({u, weight});
        }
    }

    void print()
    {
        for (auto node: adjList_W)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << "("  << neighbour.first << " , " << neighbour.second <<")";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " , ";
        visited[src] = true;

        for (auto ngbr: adjList[src])
        {
            if (!visited[ngbr])
            {
                dfs(ngbr, visited);
            }
        }
    }

};

int main()
{   
    Graph g;

    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    
    // g.addEdge(0,1,0);
    // g.addEdge(0,2,0);
    // g.addEdge(1,2,0);

    // with weights
    // g.addEdgeWithWeight(0,1,5,0);
    // g.addEdgeWithWeight(0,2,3,0);
    // g.addEdgeWithWeight(1,2,6,0);
    // g.print();

    int n = 5;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited);
        }
    }
    return 0;
}
*/