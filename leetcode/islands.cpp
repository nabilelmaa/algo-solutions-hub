#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col)
{
    if (row < 0 || col < 0 ||
        row >= grid.size() ||
        col >= grid[0].size() ||
        grid[row][col] == '0')
    {
        return;
    }

    grid[row][col] = '0';

    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}
int numIsIlands(vector<vector<char>> &grid)
{
    if (grid.empty())
    {
        return 0;
    }

    int islands = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++islands;
                dfs(grid, i, j);
            }
        }
    }
    return islands;
}
int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = line[j];
        }
    }

    cout << numIsIlands(grid) << endl;

    return 0;
}

/*
Sample input:
4 5
11000
11000
00100
00011

Sample output:
3
-----------------
Sample input:
3 3
111
111
111

Sample output:
1
-----------------
3 3
000
000
000
Sample output:
0
-----------------
5 5
11000
10100
11100
00110
00011
Sample output:
1
*/
