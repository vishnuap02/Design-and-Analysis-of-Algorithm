// undirectional graphs
// vishnu

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;
int ans = 0;
class graph
{
public:
    void addEdge(vector<int> al[], int u, int v)
    {
        al[u].push_back(v);
        al[v].push_back(u);
    }
    void DFS(int u, vector<int> adj[], vector<bool> &visited)
    {
        visited[u] = true;
        cout << u << " ";
        for (int i = 0; i < adj[u].size(); i++)
            if (visited[adj[u][i]] == false)
            {
                DFS(adj[u][i], adj, visited);
                ans++;
            }
    }
};
int32_t main()
{
    graph g;
    int n, i, e, u, v;
    cin >> n;
    int ver[n];
    vector<int> al[n];
    cout << "\n Enter number of Edges :  ";
    cin >> e;
    for (i = 0; i < e; i++)
    {
        cout << "\n Enter " << i + 1 << "th edge :  ";
        cin >> u >> v;
        g.addEdge(al, u, v);
    }
    vector<bool> visited(n, false);
    cout << "\n Enter Vertice value to start Traversal :  ";
    cin >> v; // v is node to start with
    g.DFS(v, al, visited);
    if (ans == n)
    {
        cout << "\n\n Graph is connected !";
    }
    else
    {
        cout << "\n\n Graph is Not connected !";
    }
    return 0;
}