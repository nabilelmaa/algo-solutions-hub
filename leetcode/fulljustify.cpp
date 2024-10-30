#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int index = 0;

    while (index < words.size())
    {
        int lineLength = words[index].size();
        int last = index + 1;

        while (last < words.size())
        {
            if (lineLength + words[last].size() + 1 > maxWidth)
            {
                break;
            }
            lineLength += words[last].size() + 1;
            ++last;
        }

        string line;
        int count = last - index;
        int spaces = count - 1;

        if (last == words.size() || count == 1)
        {
            for (int i = index; i < last; ++i)
            {
                line += words[i] + " ";
            }
            line.pop_back();
            while (line.size() < maxWidth)
            {
                line += " ";
            }
        }
        else
        {
            int spaceWidth = (maxWidth - lineLength) / spaces;
            int extraSpaces = (maxWidth - lineLength) % spaces;

            for (int i = index; i < last - 1; ++i)
            {
                line += words[i] + " ";
                line.append(spaceWidth + (i - index < extraSpaces ? 1 : 0), ' ');
            }
            line += words[last - 1];
        }
        result.push_back(line);
        index = last;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    int maxWidth;
    cin >> maxWidth;

    vector<string> result = fullJustify(words, maxWidth);

    cout << "[\n";
    for (const auto &line : result)
    {
        cout << "\"" << line << "\"\n";
    }
    cout << "]" << endl;

    return 0;
}

/*
Sample input:
7
This is an example of text justification.
16
Sample output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
---------------------------------------------------------
Sample input:
6
What must be acknowledgment shall be
16
Sample output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]

---------------------------------------------------------
Sample input:
18
Science is what we understand well enough to explain to a computer. Art is everything else we do
20
Sample output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
