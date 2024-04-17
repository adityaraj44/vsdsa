#include <bits/stdc++.h>

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    // put first elem of k list
    for (int i = 0; i < k; i++)
    {
        int elem = a[i][0];
        mini = min(mini, elem);
        maxi = max(maxi, elem);
        node *temp = new node(elem, i, 0);
        minHeap.push(temp);
    }

    int start = mini, end = maxi;
    while (!minHeap.empty())
    {
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }

    return end - start + 1;
}