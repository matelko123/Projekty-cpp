#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PushUnique(vector<int> &vec, int value)
{
    for (auto res : vec)
    {
        if (res == value)
            return;
    }

    vec.push_back(value);
}

int main()
{
    vector<int> result;

    cout << "Podaj n: ";
    unsigned short int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        vector<int> positions;
        long patternLenght;
        cin >> patternLenght;

        char *pattern = new char[patternLenght];
        cin >> pattern;

        string text;
        cin >> text;

        if (text.length() < patternLenght)
            continue;

        size_t startPos = 0;
        size_t foundPos = 0;
        do
        {
            foundPos = text.find(pattern, startPos++);

            if (foundPos != string::npos)
                PushUnique(positions, foundPos);

        } while (foundPos != string::npos);

        result.insert(result.end(), positions.begin(), positions.end());
    }

    cout << "Wynik:" << endl;
    for (auto res : result)
        cout << res << endl;

    return 0;
}