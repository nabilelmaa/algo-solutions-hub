#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> results;
    if (nums.size() < 3)
    {
        return results;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                results.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                {
                    ++left;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                    --right;
                }

                ++left;
                --right;
            }
            else if (sum < 0)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
    }
    return results;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    vector<vector<int>> results = threeSum(nums);

    cout << "[";
    for (int i = 0; i < results.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < results[i].size(); ++j)
        {
            cout << results[i][j];
            if (j < results[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < results.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    return 0;
}

/*
Sample input
6
-1 0 1 2 -1 -4

Sample output:
[[-1,-1,2],[-1,0,1]]

---------------------------------
Sample input
15
-2 0 3 -1 4 0 3 4 1 1 1 -3 -5 4 0

Sample output:
[[-5,1,4],[-3,-1,4],[-3,0,3],[-2,-1,3],[-2,1,1],[-1,0,1],[0,0,0]]

*/