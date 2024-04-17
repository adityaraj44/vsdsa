int findPosition(int in[], int start, int end, int target)
{

    for (int i = start; i <= end; ++i)
    {
        if (in[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node *inToPre(int in[], int pre[], int &index, int start, int end, int size)
{
    if (index >= size || start > end)
    {
        return NULL;
    }
    int element = pre[index++];
    Node *newNode = new Node(element);
    int pos = findPosition(in, start, end, element);

    newNode->left = inToPre(in, pre, index, start, pos - 1, size);
    newNode->right = inToPre(in, pre, index, pos + 1, end, size);
    return newNode;
}

Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    int index = 0;
    Node *root = inToPre(in, pre, index, 0, n - 1, n);
    return root;
}