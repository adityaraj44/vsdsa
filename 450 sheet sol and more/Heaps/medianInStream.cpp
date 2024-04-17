#include <bits/stdc++.h>

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
        return -1;
}

void callMedian(int elem, priority_queue<int> &maxHeap,
                priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))

    case 0:

        if (elem > median)
        {
            minHeap.push(elem);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(elem);
            median = maxHeap.top();
        }
    break;

case 1:
    if (elem > median)
    {
        minHeap.push(elem);
        median = (maxHeap.top() + minHeap.top()) / 2;
    }
    else
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        maxHeap.push(elem);
        median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;

case -1:
    if (elem > median)
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(elem);
        median = (maxHeap.top() + minHeap.top()) / 2;
    }
    else
    {
        maxHeap.push(elem);
        median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;
}

vector<int> findMedian(vector<int> &arr, int n)
{

    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;
    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
