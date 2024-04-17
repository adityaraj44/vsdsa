struct node *reverseIt(struct node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // step 1 reverse first k nodes
    struct node *next = NULL;
    struct node *curr = head;
    struct node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2: recursion dekhlega aageka
    if (next != NULL)
    {
        head->next = reverseIt(next, k);
    }

    // return head of reversed list
    return prev;
}