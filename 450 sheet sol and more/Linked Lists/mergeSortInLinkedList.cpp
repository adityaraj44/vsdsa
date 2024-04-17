Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *newNode = new Node(NULL);

    if (left->data <= right->data)
    {
        newNode = left;
        newNode->next = merge(left->next, right);
    }
    else
    {
        newNode = right;
        newNode->next = merge(left, right->next);
    }
    return newNode;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into two halves
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // resursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    Node *result = merge(left, right);

    return result;
}