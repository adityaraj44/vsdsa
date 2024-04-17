class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        // zero based indexing
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findParent(u);
        int up_v = findParent(v);

        if (up_u == up_v)
            return;
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};