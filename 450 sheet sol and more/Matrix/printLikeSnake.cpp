vector<int> snakePattern(vector<vector<int>> matrix)
{
    int nrow = matrix.size();
    int ncol = matrix[0].size();
    vector<int> ans;

    for (int row = 0; row < nrow; row++)
    {
        if (row % 2 != 0 || row == 1)
        {
            for (int col = ncol - 1; col >= 0; col--)
            {
                ans.push_back(matrix[row][col]);
            }
        }
        else
        {
            for (int col = 0; col < ncol; col++)
            {
                ans.push_back(matrix[row][col]);
            }
        }
    }
    return ans;
}