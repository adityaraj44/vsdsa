#define um unordered_map<int, list<int>>
#define vv vector<int>
bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    um adjList;
    for (auto i : prerequisites)
    {
        adjList[i.first].push_back(i.second);
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

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        count++;
        for (auto i : adjList[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return count == N;
}