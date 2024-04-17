void inOrder(Node *root, vector<float> &in)
{
    if (root == NULL)
        return;
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

float findMedian(struct Node *root)
{
    vector<float> in;
    inOrder(root, in);
    int n = in.size();
    float ans;
    if (n % 2 == 0)
    {
        ans = in[n / 2 - 1] + in[(n / 2)];
        ans = ans / 2;
    }
    else
    {
        ans = in[((n + 1) / 2) - 1];
    }
    return ans;
}