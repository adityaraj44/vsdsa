Node *removeDuplicates(Node *head)
{
    unordered_set<int> st;
    st.insert(head->data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (st.find(curr->next->data) != st.end())
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            st.insert(curr->next->data);
            curr = curr->next;
        }
    }

    return head;
}

// brute force
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *temp = head;
    while (temp != NULL && temp->next != NULL)
    {

        if (temp->val == temp->next->val)
        {
            ListNode *todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
        }
        else
        {

            temp = temp->next;
        }
    }
    return head;
}