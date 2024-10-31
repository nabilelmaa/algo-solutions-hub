#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];

        if (map.find(complement) != map.end())
        {
            return {map[complement], i};
        }
        map[nums[i]] = i;
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
[0, 1]
------------------
Sample input:
3
3 2 4
6
Sample output:
[1, 2]
*/