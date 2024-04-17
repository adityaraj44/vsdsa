long long minCost(long long arr[], long long n)
{

    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    long long int ans = 0;
    while (pq.size() > 1)
    {

        long long int r1 = pq.top();
        pq.pop();
        long long int r2 = pq.top();
        pq.pop();
        ans += r1 + r2;
        pq.push(r1 + r2);
    }
    return ans;
}