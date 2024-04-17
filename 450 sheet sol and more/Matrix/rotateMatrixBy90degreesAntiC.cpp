// diff from clockwise is the we have to reverse the col instead of row
void rotateby90(vector<vector<int>> &matrix, int n)
{
    //   transpose the matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    reverse(matrix.begin(), matrix.end());
}