#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<pair<int, int>> > adjList_withWeight;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        // 1 -> undirected
        // 0 -> directed
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void addEdgeWithWeight(int u, int v, int weight, bool direction)
    {
        adjList_withWeight[u].push_back({v, weight});
        // 0 -> undirected
        // 1 -> directed
        if (direction == 0)
        {
            adjList_withWeight[v].push_back({u, weight});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList_withWeight)
        {
            cout << node.first << " -> ";
            for (auto nbr : node.second)
            {
                cout << "(" << nbr.first << ", " << nbr.second << ")";
            }
            cout << endl;
        }
    }


    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList_withWeight[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }

        // parent array is created.
        // traversing parent array to find shortest path

        // or use stack instead of vector
        vector<int> ans;

        int node = dest;

        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "Printing ans : " << endl;
        for (auto i : ans)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main ()
{   

    Graph g;

    g.addEdgeWithWeight(0, 1, 1, 1);
    g.addEdgeWithWeight(1, 2, 1, 1);
    g.addEdgeWithWeight(2, 3, 1, 1);

    g.addEdgeWithWeight(3, 4, 1, 1);
    g.addEdgeWithWeight(0, 5, 1, 1);
    g.addEdgeWithWeight(5, 4, 1, 1);

    g.addEdgeWithWeight(0, 6, 1, 1);
    g.addEdgeWithWeight(6, 7, 1, 1);
    g.addEdgeWithWeight(7, 8, 1, 1);
    g.addEdgeWithWeight(8, 4, 1, 1);

    g.printAdjList();

    int src = 0;
    int dest = 4;

    g.shortestPathBFS(src, dest);

    
    return 0;
}