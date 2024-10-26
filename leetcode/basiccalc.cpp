#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int calculate(string s)
{
    stack<int> stack;
    int result = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];

        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }
        else if (ch == '+')
        {
            result += num * sign;
            num = 0;
            sign = 1;
        }
        else if (ch == '-')
        {
            result += num * sign;
            num = 0;
            sign = -1;
        }
        else if (ch == '(')
        {
            stack.push(result);
            stack.push(sign);
            result = 0;
            sign = 1;
        }
        else if (ch == ')')
        {
            result += num * sign;
            num = 0;
            result *= stack.top();
            stack.pop();
            result += stack.top();
            stack.pop();
        }
        else if (ch == ' ')
        {
            continue;
        }
    }
    if (num != 0)
    {
        result += num * sign;
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}

/*
Sample input:
"1 + 1"

Sample output:
2
------------------------
Sample input:
" 2-1 + 2 "

Sample output:
3
------------------------
Sample input:
"(1+(4+5+2)-3)+(6+8)"

Sample output:
23
*/