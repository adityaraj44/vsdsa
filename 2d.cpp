#include <bits/stdc++.h>

using namespace std;

// row wise sum
void printSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; ++j)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// col wise sum
void printSumColWise(int arr[][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; ++j)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// largest row sum
int largestRowSum(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; ++j)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    return maxi;
}

int main()
{
    // CREATE 2d ARRAY
    // can we created like this
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int arr[3][4];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // print the row sum
    cout << "Printing the row wise sum " << endl;
    printSum(arr, 3, 3);

    printSumColWise(arr, 3, 3);

    cout << largestRowSum(arr, 3, 3);

    return 0;
}