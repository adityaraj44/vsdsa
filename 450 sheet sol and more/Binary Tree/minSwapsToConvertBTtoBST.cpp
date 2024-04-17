void inOrder(vector<int> A, vector<int> &in, int n, int index)
{
    {
        if (index >= n)
        {
            return;
        }

        inOrder(A, in, n, 2 * index + 1);
        in.push_back(A[index]);
        inOrder(A, in, n, 2 * index + 2);
    }
}

int minSwaps(vector<int> &A, int n)
{
    vector<int> in;
    inOrder(A, in, n, 0);
    int noOfSwaps = 0;
    vector<pair<int, int>> t(in.size());
    // put all elements of inorder of the binary tree in pair vector
    for (int i = 0; i < t.size(); ++i)
    {
        t[i].first = in[i], t[i].second = i;
    }
    // sort according to first element of pair
    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i].second == i)
        {
            continue;
        }
        else
        {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        if (i != t[i].second)
        {
            --i;
        }
        noOfSwaps++;
    }
    return noOfSwaps;
}