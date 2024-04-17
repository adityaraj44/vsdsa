// T.c O(N)
// sc O(N);
int solve(Node *root, int K, int &i)
{
    if (root == NULL)
        return -1;
    int right = solve(root->right, K, i);

    if (right != -1)
    {
        return right;
    }

    i++;
    if (i == K)
    {
        return root->data;
    }

    return solve(root->left, K, i);
}

int kthLargest(Node *root, int K)
{
    int i = 0;
    return solve(root, K, i);
}

// S.C O(1)
int kthLargest(Node *root, int K)
{
    int i = 0;
    int large = INT_MAX;

    Node *current = root;
    while (current != NULL)
    {
        if (current->right)
        {
            Node *pred = current->right;
            while (pred->left != NULL && pred->left != current)
            {
                pred = pred->left;
            }
            if (pred->left == NULL)
            {
                pred->left = current;
                current = current->right;
            }
            else
            {
                pred->left = NULL;
                i++;
                if (i == K)
                {
                    large = current->data;
                    return large;
                }
                current = current->left;
            }
        }
        else
        {
            i++;
            if (i == K)
            {
                large = current->data;
                return large;
            }
            current = current->left;
        }
    }
    if (large != K)
        return -1;
    return large;
}