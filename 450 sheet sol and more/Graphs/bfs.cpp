// bfs if adj list given
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    queue<int> q;
    vector<int> ans;
    q.push(0);
    visited[0] = 1;
    // it is not said that the graph is disconnected
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (int i = 0; i < adj[frontNode].size(); i++)
        {
            if (!visited[adj[frontNode][i]])
            {
                q.push(adj[frontNode][i]);
                visited[adj[frontNode][i]] = 1;
            }
        }
    }

    return ans;
}

// bfs if adj not given
#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;
    queue<int> q;

    // convert to adjlist
    for (auto i : edges)
    {
        adj[i.first].insert(i.second);
        adj[i.second].insert(i.first);
    }

    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return ans;
}