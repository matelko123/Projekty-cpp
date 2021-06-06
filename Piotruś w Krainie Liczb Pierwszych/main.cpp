#include <iostream>
#include <vector>
#include <algorithm> // std::sort

using namespace std;

bool CzyPierwsza(unsigned int liczba)
{
    if (liczba < 2)
        return false;

    for (int i = 2; i * i <= liczba; i++)
        if (liczba % i == 0)
            return false;

    return true;
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

        unsigned int u = 0,
                     l = 0;

        cin >> l >> u;

        if ((u - l) > 1000000)
        {
            cout << "Incorrect input." << endl;
            continue;
        }

        unsigned int res = u;

        while (l <= u)
        {
            if (CzyPierwsza(l))
                positions.push_back(l);

            l++;
        }
        sort(positions.begin(), positions.end());
        result.insert(result.end(), positions.begin(), positions.end());
    }

    cout << "Wynik:" << endl;
    for (auto res : result)
        cout << res << endl;

    return 0;
}