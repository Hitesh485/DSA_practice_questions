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
                cout << neighbour << " , " ;
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
            //A 
            T frontNode = q.front();
            // B
            q.pop();
            //C
            cout << frontNode << " , ";
            //D -> insert neighbours 
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

        for (auto neighbour: adjList[src])
        {
            dfs(neighbour, visited);
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    g.print();

    cout << "BFS --------------> " << endl;
    // g.bfs(0); // 0  as a source node.

    // Good practice to take disconnected graph by default.
    unordered_map<int, bool> visited;
    int n = 8; // number of nodes

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
    n = 8;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }
    return 0;
}