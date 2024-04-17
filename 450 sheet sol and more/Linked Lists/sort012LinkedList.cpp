void sortDutch(vector<int> &v, int n)
{
    int l = 0;
    int m = 0;
    int h = n - 1;
    while (m >= l && m <= h)
    {
        if (v[m] == 0)
        {
            swap(v[m], v[l]);
            m++;
            l++;
        }
        else if (v[m] == 2)
        {
            swap(v[m], v[h]);
            h--;
        }
        else
            m++;
    }
}

Node *segregate(Node *head)
{

    vector<int> v;
    Node *temp = head;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n = v.size();
    sortDutch(v, n);

    temp = head;
    for (auto i : v)
    {
        temp->data = i;
        temp = temp->next;
    }
    return head;
}