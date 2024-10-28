#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col, int originalCol, char newCol)
{
    if (row < 0 ||
        col < 0 ||
        row >= grid.size() ||
        col >= grid[0].size() ||
        grid[row][col] != originalCol)
    {
        return;
    }

    grid[row][col] = newCol;
    dfs(grid, row + 1, col, originalCol, newCol); // down
    dfs(grid, row - 1, col, originalCol, newCol); // up
    dfs(grid, row, col + 1, originalCol, newCol); // right
    dfs(grid, row, col - 1, originalCol, newCol); // left
}

vector<vector<char>> floodfill(vector<vector<char>> &grid, int sr, int sc, char newColor)
{
    if (grid.empty() || grid[sr][sc] == newColor)
    {
        return grid;
    }
    int originalCol = grid[sr][sc];
    dfs(grid, sr, sc, originalCol, newColor);
    return grid;
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

    int sr, sc;
    cin >> sr >> sc;
    char newColor;
    cin >> newColor;

    grid = floodfill(grid, sr, sc, newColor);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
/*
Sample input:
3 3
111
110
101
1 1
2
Sample output:
222
220
201
-----------------
Sample input:
3 3
111
010
101
0 0
2
Sample output:
222
020
101
-----------------
Sample input:
3 3
101
010
101
1 1
2
Sample output:
101
020
101
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Cell {
    int row, col;
    Cell(int r, int c) : row(r), col(c) {}
};

vector<vector<char>> floodfill(vector<vector<char>>& grid, int sr, int sc, char newColor) {
    if (grid.empty() || grid[sr][sc] == newColor) {
        return grid;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    char originalCol = grid[sr][sc];

    stack<Cell> st;
    st.push(Cell(sr, sc));

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    while (!st.empty()) {
        Cell current = st.top();
        st.pop();

        if (grid[current.row][current.col] != originalCol) {
            continue;
        }


        grid[current.row][current.col] = newColor;


        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                grid[newRow][newCol] == originalCol) {
                st.push(Cell(newRow, newCol));
            }
        }
    }

    return grid;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = line[j];
        }
    }

    int sr, sc;
    cin >> sr >> sc;
    char newColor;
    cin >> newColor;

    grid = floodfill(grid, sr, sc, newColor);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
*/