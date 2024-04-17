Node *getStartingNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
// Function to remove a loop in the linked list.
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL)
        return;
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}