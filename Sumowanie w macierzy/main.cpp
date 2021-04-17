#include <iostream>
#include <vector>

void set(int *tab[], const int n)
{
    if (n <= 0)
        return;

    int x, y, val;
    std::cin >> x >> y >> val;

    if (x >= n || y >= n)
    {
        std::cout << "value too big" << std::endl;
        exit(1);
    }

    tab[y][x] = val;
}

int sum(int *tab[], const int n)
{
    if (n <= 0)
        return 0;

    int x1, y1, x2, y2, suma = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 >= n || y1 >= n || x2 >= n || y2 >= n)
    {
        std::cout << "value too big" << std::endl;
        exit(1);
    }

    for (int i = y1; i <= y2; i++)
    {
        for (int j = x1; j <= x2; j++)
        {
            suma += tab[i][j];
        }
    }

    return suma;
}

void printArray(int *tab[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << tab[i][j]<<"\t";
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::vector<int> solutions;
    std::cin >> n;

    int **tab = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[n];
        for(int j = 0; j < n; j++) tab[i][j] = 0;
    }

    std::string option;
    do
    {
        std::cin >> option;
        if (option == "SET")
            set(tab, n);
        else if (option == "SUM")
            solutions.push_back(sum(tab, n));
        else if (option == "PRINT")
            printArray(tab, n);

    } while (option != "END");

    for(auto i: solutions)
        std::cout<<i<<std::endl;

    // Delete array
    for (int i = 0; i < n; i++)
        delete[] tab[i];
    delete[] tab;

    return 0;
}
