// recursive
#include <bits/stdc++.h>

int solve_util(vector<vector<int>> &points, int day, int last)
{
    if (day == 0)
    {
        int mx = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }
    int mx = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int merit_points = points[day][i] + solve_util(points, day - 1, i);
            mx = max(mx, merit_points);
        }
    }
    return mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve_util(points, n - 1, 3);
}

// memoization
#include <bits/stdc++.h>

int solve_util(vector<vector<int>> &points, int day, int last,
               vector<vector<int>> &t)
{
    if (day == 0)
    {
        int mx = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }
    if (t[day][last] != -1)
        return t[day][last];
    int mx = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int merit_points = points[day][i] +
                               solve_util(points, day - 1, i, t);
            mx = max(mx, merit_points);
        }
    }
    return t[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> t(n, vector<int>(4, -1));
    return solve_util(points, n - 1, 3, t);
}

// tabulation
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> t(n, vector<int>(4, 0));
    t[0][0] = max(points[0][1], points[0][2]);
    t[0][1] = max(points[0][0], points[0][2]);
    t[0][2] = max(points[0][0], points[0][1]);
    t[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    int point = points[i][k] + t[i - 1][k];
                    t[i][j] = max(t[i][j], point);
                }
            }
        }
    }
    return t[n - 1][3];
}

// space opt
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    curr[last] = max(curr[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}