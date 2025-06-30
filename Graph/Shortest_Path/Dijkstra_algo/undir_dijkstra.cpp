#include <iostream>
#include <unordered_map>
#include <limits.h>
#include <set>
#include <vector>
#include <list>


using namespace std;

class graph
{
    public:
    unordered_map<int, list<pair<int, int>> > adjList;

    void edgeList(int u, int v, int wght, bool direction)
    {
        adjList[u].push_back({v, wght});

        // 1 -> directed
        if (direction == 1)
        {
            adjList[v].push_back({u, wght});
        }
    }
    
    void printAdjList()
    {
        for (auto node : adjList){
            cout << node.first << " -> ";
            for (auto nbr : node.second)
            {
                cout <<
                    "(" << nbr.first << ", " << nbr.second << ")";
            }
            cout << endl;
        }
    }

    void Dijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first element from set.
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node  = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // update the distance
                    // first find the entry in set

                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    // updatation in distance array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout << "pirnting ans: " << endl;
        for (auto i : dist)
        {
            cout << i << ", ";
        }
        cout << endl;

    }

};

int main ()
{
    graph g;

    g.edgeList(6,3,2,1);
    g.edgeList(6,1,14,1);
    g.edgeList(3,1,9,1);
    g.edgeList(3,2,10,1);

    g.edgeList(1,2,7,1);
    g.edgeList(2,4,15,1);
    g.edgeList(4,3,11,1);

    g.edgeList(6,5,9,1);
    g.edgeList(4,5,6,1);

    g.printAdjList();

    int src = 6;
    // n = number of nodes.
    int n = 7;
    g.Dijkstra(src, n);

    return 0;
}