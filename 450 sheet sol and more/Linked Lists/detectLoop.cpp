bool isCircular(Node *head)
{
    if (head == NULL)
        return true;
    Node *temp = head;
    unordered_map<Node *, bool> mp;
    while (temp != NULL)
    {
        if (mp[temp] == true)
            return true;
        else
            mp[temp] = true;
        temp = temp->next;
    }
    return false;
}
// floyd's cycle detection
bool detectLoop(Node *head)
{
    // floydd detect loop
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

