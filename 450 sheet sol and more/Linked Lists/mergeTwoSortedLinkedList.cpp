// recursive
Node *sortedMerge(Node *head1, Node *head2)
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
        n->next = sortedMerge(head1->next, head2);
    }
    else
    {
        n = head2;
        n->next = sortedMerge(head1, head2->next);
    }
    return n;
}

// iterative
Node *sortedMerge(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->next;
            }
            else
            {
                tail->next = head2;

                tail = head2;
                head2 = head2->next;
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;
            head2 = head2->next;
        }
        else
        {
            tail->next = head2;

            tail = head2;
            head2 = head2->next;
        }
    }
    return head;
}