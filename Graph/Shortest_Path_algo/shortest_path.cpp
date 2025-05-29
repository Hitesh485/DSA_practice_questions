#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int src, int dest, int weight, bool direction)
    {
        // 0 -> directed
        // 1 -> undirected
        adjList[src].push_back({dest, weight});
        if (direction == 0)
        {
            adjList[dest].push_back({src, weight});
        }
    }

    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // init step for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = 1; // true mark
                    parent[nbr.first] = fNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }


        //reverse -> ans
        // int i = 0;
        // int j = ans.size()-1;
        // while (i < j)   
        // {
        //     swap(ans[i++], ans[j--]);
        // }
        // OR
        reverse(ans.begin(), ans.end());

        cout << "Printing ans: " << endl;
        for (auto i : ans)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{

    Graph g;
    g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 1, 1);

    g.addEdge(3, 4, 1, 1);
    g.addEdge(0, 5, 1, 1);
    g.addEdge(5, 4, 1, 1);

    g.addEdge(0, 6, 1, 1);
    g.addEdge(6, 7, 1, 1);
    g.addEdge(7, 8, 1, 1);
    g.addEdge(8, 4, 1, 1);

    g.print();

    int src = 0;
    int dest = 4;

    g.shortestPathBFS(src, dest);

    return 0;
}