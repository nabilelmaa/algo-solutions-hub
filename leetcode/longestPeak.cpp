#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int longestPeak(vector<int> &array)
{
    if (array.size() < 3)
    {
        return 0;
    }

    /*
    array = [0, 1, 2, 4]
    array[i] = 1
    array[i - 1] = 0
    array[i + 1] = 2

    1 > 0 && 1 > 2  => check if the current element is a peak
    */

    int longestPeak = 0;
    for (int i = 1; i < array.size() - 1; ++i)
    {
        if (array[i] > array[i - 1] && array[i] > array[i + 1])
        {
            int leftIndex = i - 1;
            int rightIndex = i + 1;

            while (leftIndex > 0 && array[leftIndex] > array[leftIndex - 1])
            {
                --leftIndex;
            }

            while (rightIndex < array.size() - 1 && array[rightIndex] > array[rightIndex + 1])
            {
                ++rightIndex;
            }
            int peakLength = rightIndex - leftIndex + 1;

            longestPeak = max(longestPeak, peakLength);

            i = rightIndex;
        }
    }
    return longestPeak;
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    cout << longestPeak(array) << endl;
    return 0;
}

/*

Sample input:
13
1 2 3 3 4 0 10 6 5 -1 -3 2 3

Sample output:
6
----------------
Sample input:
6
1 2 3 4 5 1

Sample output:
6
----------------
Sample input:
13
5 4 3 2 1 2 10 12 -3 5 6 7 10

Sample output:
5
*/