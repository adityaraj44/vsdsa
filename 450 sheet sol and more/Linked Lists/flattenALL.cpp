Node *merge(Node *head1, Node *head2)
{
    Node *n = new Node(NULL);

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        n = head1;
        n->bottom = merge(head1->bottom, head2);
    }
    else
    {
        n = head2;
        n->bottom = merge(head1, head2->bottom);
    }
    return n;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    Node *right = flatten(root->next);
    root->next = NULL;
    Node *ans = merge(root, right);
    return ans;
}
