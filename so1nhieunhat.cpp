#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int row_with_max_1s(vector<vector<int>> matrix)
{
    int max_one_index = 0;

    int curr_pos = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        while (curr_pos <= (matrix[0].size() - 1) && matrix[i][curr_pos] == 1)
        {
            curr_pos = curr_pos + 1;
            max_one_index = i;
        }
    }
    return max_one_index;
}

int main()
{
    vector<vector<int>> matrix = {
        {
            1,
            1,
            1,
            0,
            0,
        },
        {
            1,
            0,
            0,
            0,
            0,
        },
        {
            1,
            1,
            1,
            0,
            0,
        },
        {1, 1, 1, 1, 0}};

    cout << row_with_max_1s(matrix);

    return 0;
}
