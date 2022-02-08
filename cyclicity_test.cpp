// cyclicity in  graphs
// vishnu
// This graph doesnt print number of cycles

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;
vector<int> ans;
class graph
{
public:
    void addEdge(vector<int> al[], int u, int v)
    {
        al[u].push_back(v);
        al[v].push_back(u);
    }
    bool isCyclicUtil(int v, bool visited[], vector<int> adj[])
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            vector<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if ((visited[*i]) && !(isCyclicUtil(*i, visited, adj)))
                {
                    cout << *i << "  ";
                    return true;
                }
                visited[*i] = false;
            }
        }
        return false;
    }
    bool isCyclic(vector<int> adj[], int V)
    {
        for (int i = 0; i < V; i++)
        {
            bool visited[V] = {false};
            if (isCyclicUtil(i, visited, adj))
                return true;
        }
        return false;
    }
};
int32_t main()
{
    graph g;
    int n, i, e, u, v;
    cin >> n;
    int ver[n];
    vector<int> al[n];
    // cout << "\n Enter number of Edges :  ";
    cin >> e;
    for (i = 0; i < e; i++)
    {
        // cout << "\n Enter " << i + 1 << "th edge :  ";
        cin >> u >> v;
        g.addEdge(al, u, v);
    }
    if (g.isCyclic(al, n))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}