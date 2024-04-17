// dfs logic
#include <bits/stdc++.h>

bool isCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    dfsVisited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            bool cycle = isCycleDFS(i, visited, dfsVisited, adj);
            if (cycle)
            {
                return true;
            }
        }
        else if (dfsVisited[i] == 1)
        {
            // if visited and dfs visited true
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    // call dfs for all components
    for (int i = 1; i <= 5; i++)
    {
        if (!visited[i])
        {
            bool cycle = isCycleDFS(i, visited, dfsVisited, adj);
            if (cycle)
            {
                return true;
            }
        }
    }
    return false;
}

// bfs logic using Kahn's algo
#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(n + 1);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree ko push krdo
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (count == n)
    {
        return false;
    }
    else
        return true;
}