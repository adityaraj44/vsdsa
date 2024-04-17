#include <bits/stdc++.h>

using namespace std;

int setBits(int N)
{ 
    int count = 0;
    while (N != 0)
    {
        if (N & 1)
        {
            count++;
        }
        N = N >> 1;
    }
    return count;
}

int main()
{
    cout << setBits(5) << endl;
    return 0;
}