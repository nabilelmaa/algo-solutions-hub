#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxLeft, maxRight;
    maxLeft = maxRight = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                water += maxLeft - height[left];
            }
            ++left;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                water += maxRight - height[right];
            }
            --right;
        }
    }
    return water;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> height[i];
    }

    cout << trap(height) << endl;

    return 0;
}

/*
Sample input:
12
0 1 0 2 1 0 1 3 2 1 2 1
Sample output:
6
-------------------------
Sample input:
6
4 2 0 3 2 5
Sample output:
9
-------------------------
Sample input:
9
1 0 2 1 0 1 3 2 0
Sample output:
5
*/