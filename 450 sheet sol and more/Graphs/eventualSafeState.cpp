// dfs
class Solution
{
private:
    bool dfs(int node, int visited[], int dfsVisited[], vector<int> adj[], int mark[])
    {
        visited[node] = 1;
        dfsVisited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, visited, dfsVisited, adj, mark) == true)
                {
                    mark[it] = 0;
                    return true;
                }
            }
            else if (dfsVisited[it])
            {
                mark[it] = 0;
                return true;
            }
        }
        dfsVisited[node] = 0;
        mark[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int dfsVisited[V] = {0};
        int mark[V] = {0};
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, dfsVisited, adj, mark);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};

// bfs - toposort logic
class Solution
{

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        // bfs logic
        // reverse the edges and implement topo sort logic
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                indegree[i]++;
                adjRev[it].push_back(i);
            }
        }
        vector<int> safeNodes;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};