bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    bool leftAns = isIdentical(r1->left, r2->left);
    bool rightAns = isIdentical(r1->right, r2->right);

    bool condition = r1->data == r2->data;

    if (leftAns && rightAns && condition)
    {
        return true;
    }
    else
    {
        return false;
    }
}