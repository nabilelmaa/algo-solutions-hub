#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; ++j)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; ++i)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid) << endl;

    return 0;
}

/*
Sample input:
3 3
1 3 1
1 5 1
4 2 1
Sample output:
7
----------------
Sample input:
2 3
1 2 3
4 5 6
Sample output:
12
----------------
Sample input:
5 4
1 3 1 4
1 5 1 2
3 2 1 1
1 5 2 4
2 1 3 3
Sample output:
15
*/