#include <bits/stdc++.h>

void dfs(int node, vector<bool> &visited, stack<int> &st,
         unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }
    st.push(node);
}

void revdfs(int node, vector<bool> &visited,
            unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto i : transpose[node])
    {
        if (!visited[i])
        {
            revdfs(i, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // transpose the graph
    unordered_map<int, list<int>> transpose; // reverse of initial adjlist
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // dfs call using above ordering and transpose
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            revdfs(top, visited, transpose);
        }
    }

    return count;
}
