class Solution
{
public:
    void dfs(int node, int parent, unordered_map<int, list<int>> &adjList, vector<bool> &visited, vector<int> &time,
             vector<int> &low, vector<vector<int>> &bridges, int timer)
    {
        visited[node] = true;
        time[node] = low[node] = timer++;

        for (auto it : adjList[node])
        {
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, adjList, visited, time, low, bridges, timer);
                low[node] = min(low[node], low[it]);

                if (low[it] > time[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]); // or time[it]
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, list<int>> adjList(n);
        for (int i = 0; i < connections.size(); i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);
        vector<int> time(n);
        vector<int> low(n);

        vector<vector<int>> bridges;
        int timer = 0;
        dfs(0, -1, adjList, visited, time, low, bridges, timer);

        return bridges;
    }
};