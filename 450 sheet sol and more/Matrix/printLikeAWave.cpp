#include <bits/stdc++.h>
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> result;
    for (int col = 0; col < mCols; col++)
    {
        if (col % 2 != 0 || col == 1)
        {
            // odd index- bottom to top
            for (int row = nRows - 1; row >= 0; row--)
            {
                result.push_back(arr[row][col]);
            }
        }
        else
        {   
            // zero or even index
            for (int row = 0; row < nRows; row++)
            {
                result.push_back(arr[row][col]);
            }
        }
    }
    return result;
}

// time complexity
// O(n*m)
