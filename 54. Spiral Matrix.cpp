class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<vector<int>> directionMatrix = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // direction Matrix
        vector<int> result;

        int r = matrix.size(); // No.of Rows
        if (r == 0)
            return result;

        int c = matrix[0].size(); // No.of Columns
        if (c == 0)
            return result;

        vector<int> numSteps = {c, r - 1}; // Number of horizontal and vertical steps

        int indexDirection = 0;                 // index of direction.
        int initialRow = 0, initialColumn = -1; // initial position

        while (numSteps[indexDirection % 2])
        {
            for (int i = 0; i < numSteps[indexDirection % 2]; ++i)
            {

                initialRow += directionMatrix[indexDirection][0];
                initialColumn += directionMatrix[indexDirection][1];

                result.push_back(matrix[initialRow][initialColumn]);
            }
            numSteps[indexDirection % 2]--;
            indexDirection = (indexDirection + 1) % 4;
        }
        return result;
    }
};