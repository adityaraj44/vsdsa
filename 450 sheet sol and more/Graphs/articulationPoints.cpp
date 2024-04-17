class Solution
{
public:
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &tim,
             vector<int> &low, vector<int> &points, int timer)
    {
        visited[node] = true;
        tim[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, adj, visited, tim, low, points, timer);
                low[node] = min(low[node], low[it]);

                // check
                if (low[it] >= tim[node] && parent != -1)
                {
                    points[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tim[it]);
            }
        }
        if (parent == -1 && child > 1)
        {
            points[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> tim(V);
        vector<int> low(V);
        vector<int> points(V, 0);
        vector<int> ans;

        int timer = 0;
        dfs(0, -1, adj, visited, tim, low, points, timer);

        for (int i = 0; i < V; i++)
        {
            if (points[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
    }
};