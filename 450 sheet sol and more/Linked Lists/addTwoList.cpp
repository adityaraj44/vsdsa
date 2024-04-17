voidNode *reverse(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *head = NULL;
    while (first != NULL && second != NULL)
    {
        int sum = first->data + second->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        insert(head, sum);
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        int sum = first->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        insert(head, sum);
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = second->data + carry;
        carry = sum / 10;
        sum = sum % 10;

        insert(head, sum);

        second = second->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;

        insert(head, sum);
    }
    return head;
}

Node *addTwoLists(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);

    // add 2 LL
    Node *ans = add(first, second);

    // reverse ans
    ans = reverse(ans);

    return ans;
}