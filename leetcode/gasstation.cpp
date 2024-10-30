#include <iostream>
#include <vector>

using namespace std;

int students[25];

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    if (gas.size() != cost.size())
    {
        return -1;
    }

    int totalGas = 0, totalCost = 0, startingStation = 0, tank = 0;

    for (int i = 0; i < gas.size(); ++i)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        if (tank < 0)
        {
            startingStation = i + 1;
            tank = 0;
        }
    }

    return totalGas >= totalCost ? startingStation : -1;
}

int main()
{

    int n;
    cin >> n;

    vector<int> gas(n);
    vector<int> cost(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> gas[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> cost[i];
    }

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}

/*
Sample input
5
1 2 3 4 5
3 4 5 1 2

Sample output:
3

---------------------------------
Sample input
3
2 3 4
3 4 3

Sample output:
-1
*/




