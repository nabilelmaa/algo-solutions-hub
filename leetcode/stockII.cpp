#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}
int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;

    return 0;
}

/*

Sample input:
6
7 1 5 3 6 4

Sample output:
7
----------------
Sample input:
5
1 2 3 4 5

Sample output:
4
----------------
Sample input:
5
7 6 4 3 1

Sample output:
0
*/