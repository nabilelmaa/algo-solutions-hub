#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    if (arr.empty())
    {
        return -1;
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cin >> target;

    cout << binarySearch(arr, target) << endl;
    return 0;
}
/*
Sample input:
10
0 1 21 33 45 45 61 71 72 73
33
Sample output:
3
-----------------------------
Sample input:
7
1 2 3 4 5 6 7
10
Sample Output:
-1
-----------------------------
Sample input:
5
10 20 30 40 50
10
Sample Output:
0
*/
