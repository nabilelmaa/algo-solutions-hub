#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int prev = 0;
    int sum = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        char ch = s[i];
        int curr = map[ch];

        if (curr >= prev)
        {
            sum += curr;
        }
        else
        {
            sum -= curr;
        }

        prev = curr;
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        cout << romanToInt(s) << endl;
    }
    return 0;
}

// t here is the number of test cases.

/*
Sample input:
4
IV
VI
MMI
MMXXIV
Sample output:
4
6
2001
2024
*/
