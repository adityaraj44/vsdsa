// literally get the count of number of components
void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    // given is adj matrix
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjList[i + 1].push_back(j + 1);
                adjList[j + 1].push_back(i + 1);
            }
        }
    }

    // visited
    vector<bool> visited(V);
    // count of provinces
    int cnt = 0;
    // dfs
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i, visited, adjList);
        }
    }

    return cnt;
}