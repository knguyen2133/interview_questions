// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    // outter to inner, via columns horizontal
    void reflect(vector<vector<int>> &matrix)
    {
        auto size = matrix.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size / 2; ++j)
            {
                auto temp = matrix[i][j];
                // swap with opposite end of the row
                matrix[i][j] = matrix[i][size - j - 1];
                matrix[i][size - j - 1] = temp;
            }
        }
    }

    // outer to inner, diagonally
    void transpose(vector<vector<int>> &matrix)
    {
        auto size = matrix.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                auto temp = matrix[i][j];
                // swap with the tranpose column
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reflect(matrix);
    }
};