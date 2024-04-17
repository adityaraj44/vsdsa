#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // dist arry
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        // fetch top
        auto top = *(st.begin());
        int nodeDist = top.first;
        int node = top.second;
        st.erase(st.begin());

        // traverse on neighbours

        for (auto i : adj[node])
        {
            if (nodeDist + i.second < dist[i.first])
            {
                auto record = st.find(make_pair(dist[i.first], i.first));
                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[i.first] = nodeDist + i.second;
                st.insert({dist[i.first], i.first});
            }
        }
    }
    return dist;
}
