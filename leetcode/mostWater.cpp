#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxArea(vector<int> &heights)
{
    int left = 0;
    int right = heights.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int currentArea = (right - left) * min(heights[left], heights[right]);

        maxArea = max(maxArea, currentArea);

        if (heights[left] < heights[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return maxArea;
}
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    cout << maxArea(heights) << endl;
    return 0;
}

/*
Sample input:
9
1 8 6 2 5 4 8 3 7
Sample output:
49
------------------
Sample input:
2
1 1
Sample output:
1
*/