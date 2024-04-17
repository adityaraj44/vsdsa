/*
O(n*m)
*/

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{

    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int totalElements = row * col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < totalElements)
    {
        // print starting row
        for (int index = startingCol; count < totalElements && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending col
        for (int index = startingRow; count < totalElements && index <= endingRow; index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // print ending row
        for (int index = endingCol; count < totalElements && index >= startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // print staring col
        for (int index = endingRow; count < totalElements && index >= startingRow; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}