Node *flatten(Node *root)
{
    vector<Node *> in;
    inOrderToNodeArray(root, in);
    int size = in.size();

    Node *newRoot = new Node(in[0]->data);
    Node *curr = newRoot;
    for (int i = 1; i < size; i++)
    {
        curr->left = NULL;
        curr->right = in[i];
        curr = in[i];
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
