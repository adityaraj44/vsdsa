void populateNext(Node *root)
{
    // code here
    vector<Node *> in;
    inOrder(root, in);
    for (int i = 0; i < in.size() - 1; i++)
    {
        in[i]->next = in[i + 1];
    }
}