bool check(Node *root)
{
    // Your code here
    queue<Node *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; ++i)
        {
            Node *front = q.front();
            q.pop();

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
            if (front->left == NULL && front->right == NULL)
            {
                flag = 1;
            }
        }
        if (flag && !q.empty())
        {
            return 0;
        }
    }
    return 1;
}