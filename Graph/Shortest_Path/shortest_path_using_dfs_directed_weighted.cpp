#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<pair<int, int>>> adjList_withWeight;

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

    void topoSort(int src, unordered_map<int, bool> &visited, stack<int> &st)
    {
        // dfs code topological sort
        visited[src] = true;

        for (auto nbr : adjList_withWeight[src])
        {
            if (!visited[nbr.first])
            {
                topoSort(nbr.first, visited, st);
            }
        }

        st.push(src);
    }


    void shortestPathDFS(int dest, stack<int> topoOrder, int n)
    {
        vector<int> distance(n, INT_MAX);

        int src = topoOrder.top();
        // topoOrder.pop();
        distance[src] = 0;

        while (!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            // cout << "top ele ************* "<< topElement << endl;
            topoOrder.pop();

            if (distance[topElement] != INT_MAX)
            {
                for (auto nbr : adjList_withWeight[topElement])
                {
                    if ((distance[topElement] + nbr.second) < distance[nbr.first])
                    {
                        distance[nbr.first] = (distance[topElement] + nbr.second);
                    }
                }
            }
        }

        cout << "Printing ans : " << endl;
        for (auto i : distance)
        {
            cout << i << ", " ;
        }
        cout << endl;
    }

};

int main()
{

    Graph g;

    // n is nothing but number of nodes.
    int n = 5;

    g.addEdgeWithWeight(0, 1, 5, 1);
    g.addEdgeWithWeight(0, 2, 3, 1);
    g.addEdgeWithWeight(2, 1, 2, 1);

    g.addEdgeWithWeight(1, 3, 3, 1);
    g.addEdgeWithWeight(2, 3, 5, 1);
    g.addEdgeWithWeight(2, 4, 6, 1);
    g.addEdgeWithWeight(4, 3, 1, 1);

    // g.printAdjList();

    // int src = 0;
    // int dest = 4;

    // g.shortestPathBFS(src, dest);

    unordered_map<int, bool> visited;
    stack<int> topoOrder;

    g.topoSort(0, visited, topoOrder);

    int dest = 3;
    g.shortestPathDFS(dest, topoOrder, n);

    return 0;
}