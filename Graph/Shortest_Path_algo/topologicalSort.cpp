#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void topolocialSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;
        for (auto negihbour : adjList[src])
        {
            if (!visited[negihbour])
            {
                topolocialSortDFS(negihbour, visited, ans);
            }
        }
        return ans.push(src);
    }

    void topologicalSortBFS()
    {
        
    }


    void printAdjacencyList()
    {
        cout << endl;
        for (auto node: adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 7, 1);


    g.printAdjacencyList();
    cout << endl;

    int n = 8;
    unordered_map<int, bool> visited;
    stack<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topolocialSortDFS(i, visited, ans);
        }
    }

    // printing stack
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    return 0;
}