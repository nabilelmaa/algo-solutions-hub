#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void toDescending(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        ++left;
        --right;
    }
}
int hIndex(vector<int> &citations)
{
    toDescending(citations);

    for (int i = 0; i < citations.size(); ++i)
    {
        int paper = i + 1;
        if (citations[i] < paper)
        {
            return i;
        }
    }
    return citations.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> citations(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> citations[i];
    }

    cout << hIndex(citations) << endl;
    return 0;
}

/*
Sample input:
5
3 0 6 1 5

Sample output:
3
-----------------
Sample input:
3
1 3 1

Sample output:
1
*/