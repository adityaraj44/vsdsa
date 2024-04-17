// T.c O(N)
// sc O(N);
int solve(Node *root, int K, int &i)
{
    if (root == NULL)
        return -1;
    int left = solve(root->left, K, i);

    if (left != -1)
    {
        return left;
    }

    i++;
    if (i == K)
    {
        return root->data;
    }

    return solve(root->right, K, i);
}

int KthSmallestElement(Node *root, int K)
{
    // add code here.
    int i = 0;
    return solve(root, K, i);
}

// morris traversal O(N) and sc O(1)

int KthSmallestElement(Node *root, int K)
{
    // add code here.
    int i = 0;
    int small = INT_MIN;

    Node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                i++;
                if (i == K)
                {
                    small = current->data;
                    return small;
                }
                current = current->right;
            }
        }
        else
        {
            i++;
            if (i == K)
            {
                small = current->data;
                return small;
            }
            current = current->right;
        }
    }
    if (small != K)
        return -1;
    return small;
}