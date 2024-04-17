void bstToDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    bstToDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    bstToDLL(root->left, head);
}

Node *mergeDLL(Node *head1, Node *head2)
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
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;
            head1 = head1->right;
        }
        else
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;
            head2 = head2->right;
        }
        else
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }
    return head;
}

int countNodes(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *dllToBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = dllToBST(head, n / 2);
    Node *root = head;
    root->left = left;

    head = head->right;

    root->right = dllToBST(head, n - n / 2 - 1);
    return root;
}

void inOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> merge(Node *root1, Node *root2)
{
    // convert bst to dll
    Node *head1 = NULL;
    bstToDLL(root1, head1);
    Node *head2 = NULL;
    bstToDLL(root2, head2);
    // merge dll
    Node *head = mergeDLL(head1, head2);

    // get count of nodes of merged dll
    int n = countNodes(head);
    // dll to bst
    Node *root = dllToBST(head, n);
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}