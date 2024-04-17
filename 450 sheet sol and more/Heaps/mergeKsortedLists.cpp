class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // put first k elem
    int k = listArray.size();

    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        if (head == NULL)
        {
            // list was empty
            head = top;
            tail = top;
        }
        else
        {
            // insert at linked list
            tail->next = top;
            tail = top;
        }
    }

    return head;
}