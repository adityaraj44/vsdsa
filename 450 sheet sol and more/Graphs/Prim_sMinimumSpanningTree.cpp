#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1); // can also be said as visited arr
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {

        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (mst[node])
        {
            continue;
        }

        // mark min to True
        mst[node] = true;

        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = node;
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    // the first elem's parent will be -1 so no need to include
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
