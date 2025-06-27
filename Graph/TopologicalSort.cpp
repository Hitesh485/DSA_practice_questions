#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <stack>
#include <vector>


// Topological sort using bfs also knows as Kahn's Algorithm.

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, list<pair<int, int>>> adjList_W;

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
        for (auto node : adjList_W)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << " , " << neighbour.second << ")";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " , ";
        visited[src] = true;

        for (auto ngbr : adjList[src])
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

    bool cyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = cyclicUsingDFS(nbr, visited, src);
                if (checkAageKaAns == true)
                {
                    true;
                }
            }
            else if (visited[nbr] && nbr != parent)
            {
                // cycle present
                return true;
            }
        }
        return false;
    }

    bool CheckCyclicDirectedUsingDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool ans = CheckCyclicDirectedUsingDFS(nbr, visited, dfsVisited);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        // yha glti k chances hai
        // backtracking
        dfsVisited[src] = false;
        return false;
    }

    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        // similar structure as in dfs
        visited[src] = true;

        for (auto nbr: adjList[src])
        {
            if (!visited[nbr])
            {

                topologicalSortDFS(nbr, visited, ans);
            }
        }

        // while returning store the node in stack
        ans.push(src);
    }


    void topologicalSortUsingBFS(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculate
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue which indegree is 0
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs logic
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            // cout << fNode << " , ";
            ans.push_back(fNode);
            // or we can use count var to count nodes for check valid or invalid topolical sort. cout++

            for (auto nbr : adjList[fNode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }


            }
        }
    }
};

int main()
{
    Graph g;


    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);

    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);




    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);

    // g.addEdge(3, 5, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(6, 7, 1);


    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(4, 2, 1);

    // g.addEdge(0,1,0);
    // g.addEdge(0,2,0);
    // g.addEdge(1,2,0);

    // with weights
    // g.addEdgeWithWeight(0,1,5,0);
    // g.addEdgeWithWeight(0,2,3,0);
    // g.addEdgeWithWeight(1,2,6,0);
    // g.print();




    int n = 8;
    // unordered_map<int, bool> visited;
    // bool ans = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         // g.dfs(i, visited);
    //         ans = g.cyclicUsingDFS(i, visited, -1);
    //         if (ans == true)
    //         {
    //             break;
    //         }
    //     }
    // }

    // if (ans == true)
    // {
    //     cout << "Cycle detected!" << endl;
    // }
    // else
    // {
    //     cout << "Cycle not detected!" << endl;
    // }





    // bool ans = false;
    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsVisited;

    // for (int i = 0; i < n; i++)
    // {
    //     ans = g.CheckCyclicDirectedUsingDFS(ans, visited, dfsVisited);
    //     if (ans == true)
    //     {
    //         break;
    //     }
    // }

    // if (ans == true)
    // {
    //     cout << "Cycle found " << endl;
    // }
    // else
    // {
    //     cout << "Cycle not found " << endl;
    // }



    // unordered_map<int, bool> visited;
    // stack<int> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.topologicalSortDFS(i, visited, ans);
    //     }
    // }

    // cout << "Topological sort: " << endl;

    // while (!ans.empty())
    // {
    //     cout << ans.top() << " , " ;
    //     ans.pop();
    // }



    cout << "Printing topological sort using BFS : "  << endl;
    vector<int> ans;
    g.topologicalSortUsingBFS(n, ans);
    
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " , ";
    }
    cout << endl;

    // Check cyclic graph or not 
    if (ans.size() == n) // cyclic not exit
    {
        cout << "Cycle not present!! Valid topolical sort" << endl;
    }
    else // cycle present
    {
        cout << "Cycle present and invalid topolical sort" << endl;
    }


    return 0;
}