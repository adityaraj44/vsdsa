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

Node *copyList(Node *head)
{
    // Write your code here
    //  cloned the original list using its next pointer
    Node *cloneHead = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insert(cloneHead, temp->data);
        temp = temp->next;
    }

    // mapping
    unordered_map<Node *, Node *> oldToNewNode;

    Node *orgNode = head;
    Node *cloneNode = cloneHead;
    while (orgNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[orgNode] = cloneNode;
        orgNode = orgNode->next;
        cloneNode = cloneNode->next;
    }

    orgNode = head;
    cloneNode = cloneHead;

    while (orgNode != NULL)
    {
        cloneNode->arb = oldToNewNode[orgNode->arb];
        orgNode = orgNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

// space complexity O(1)
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

Node *copyList(Node *head)
{

    // step 1 - create a clone list
    Node *cloneHead = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insert(cloneHead, temp->data);
        temp = temp->next;
    }

    // step 2: clone node in between original nodes

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3: random pointer copy
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        if (originalNode->next != NULL)
        {
            originalNode->next->arb = originalNode->arb ? originalNode->arb->next : originalNode->arb;
        }

        originalNode = originalNode->next->next;
    }

    // step 4: revert changes done in step 2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }

        cloneNode = cloneNode->next;
    }

    // step 5: return ans
    return cloneHead;
}