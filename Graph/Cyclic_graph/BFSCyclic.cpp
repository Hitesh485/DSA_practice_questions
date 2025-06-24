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

    bool cycleDetectUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else
                {
    // already visited && not a parent (jis node (frontNode) se aye the vo parent nahi h)
                    if (nbr != parent[frontNode])
                    {
                        // cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }


};

int main()
{   
    Graph g;

    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(4, 0, 0);
        
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 6, 0);

    
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
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // g.dfs(i, visited);
            ans = g.cycleDetectUsingBFS(i, visited);
            if (ans == true)
            {
                break;
            }
        }
    }

    if (ans == true)
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "Cycle not detected!" << endl;
    }
    return 0;
}