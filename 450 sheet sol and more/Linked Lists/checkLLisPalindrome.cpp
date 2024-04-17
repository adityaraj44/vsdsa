// sc O(N)
bool isPalindrome(Node *head)
{
    vector<int> v;
    Node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int k = v.size() - 1;
    for (int i = 0; i <= k; i++)
    {
        if (v[i] == v[k])
        {
            k--;
        }
        else
            return false;
    }
    return true;
}

// sc O(1)

Node *getmiddle(Node *head)
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

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    // get middle node
    Node *middle = getmiddle(head);

    // reverse the node ahead of middle
    Node *head2 = reverse(middle->next);
    Node *head1 = head;

    // compare the original head and second head assigned to middle->next
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    middle->next = reverse(middle->next);
    return true;
}
