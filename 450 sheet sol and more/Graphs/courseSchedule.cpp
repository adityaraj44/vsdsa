#define um unordered_map<int, list<int>>
#define vv vector<int>
vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites)
{
    um adjList;
    for (auto i : prerequisites)
    {
        adjList[i[1]].push_back(i[0]);
    }

    vv indegree(N);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adjList[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vv topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for (auto i : adjList[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (topo.size() == N)
        return topo;
    else
        return {};
}