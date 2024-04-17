#include <bits/stdc++.h>

bool isSafe(int x, int y, vector<vector<int>> &arr, int n, vector<vector<int>> &visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && arr[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<int>> &visited, vector<string> &ans, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // for down
    if (isSafe(x + 1, y, arr, n, visited))
    {
        path.push_back('D');
        solve(x + 1, y, arr, n, visited, ans, path);
        path.pop_back();
    }

    // for left
    if (isSafe(x, y - 1, arr, n, visited))
    {
        path.push_back('L');
        solve(x, y - 1, arr, n, visited, ans, path);
        path.pop_back();
    }
    // for right
    if (isSafe(x, y + 1, arr, n, visited))
    {
        path.push_back('R');
        solve(x, y + 1, arr, n, visited, ans, path);
        path.pop_back();
    }
    // for up
    if (isSafe(x - 1, y, arr, n, visited))
    {
        path.push_back('U');
        solve(x - 1, y, arr, n, visited, ans, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    // create a string ans
    vector<string> ans;

    // edge case
    if (arr[0][0] == 0)
    {
        return ans;
    }

    // create a visited array
    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";

    // a solve function
    solve(0, 0, arr, n, visited, ans, path);

    return ans;
}