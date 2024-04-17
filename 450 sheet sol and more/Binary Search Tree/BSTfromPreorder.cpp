Node *solvePreOrderToBST(vector<int> preOrder, int max, int &i)
{
    if (i >= preOrder.size() || preOrder[i] > max)
    {

        return NULL;
    }

    Node *root = new Node(preOrder[i++]);
    root->left = solvePreOrderToBST(preOrder, root->data, i);
    root->right = solvePreOrderToBST(preOrder, max, i);
    return root;
}

Node *preOrderToBST(vector<int> preOrder)
{

    int max = INT_MAX;
    int i = 0;
    return solvePreOrderToBST(preOrder, max, i);
}