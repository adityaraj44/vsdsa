string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> indegree(K, 0);
    for (int i = 0; i < K; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }
    return ans;
}