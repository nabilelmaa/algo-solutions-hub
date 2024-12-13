#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            return {left + 1, right + 1};
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
    return {};
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

    int target;
    cin >> target;

    vector<int> result = twoSum(nums, target);
    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}

/*
Sample input:
4
2 7 11 15
9
Sample output:
[1, 2]
------------------
Sample input:
3
2 3 4
6
Sample output:
[1, 3]
------------------
Sample input:
2
-1 0
-1
Sample output:
[1, 2]
*/