#include <iostream>

int liczbaWywazona(int liczba)
{
    // std::cout<<"Sprawdzana liczba: "<<liczba+1<<std::endl;
    int dzielnik = 1,
        parz = 0,
        nieparz = 0;

    do
    {
        if(liczba % dzielnik == 0)
        {
            if(dzielnik % 2 == 0) parz++;
            else nieparz++;
        }

        dzielnik++;
    } while (dzielnik <= liczba);

    // std::cout<<"Parzyste dzielniki: "<<parz<<"\tNieparzyste dzielniki: "<<nieparz<<std::endl;

    if(parz != nieparz) return liczbaWywazona(liczba + 1);
    return liczba;
}

int main()
{
    int n;
    // std::cout << ": ";
    std::cin >> n;

    int *tab = new int[n];

    for (int i = 0; i < n; i++)
    {
        // std::cout << "tab[" << i << "]: ";
        std::cin >> tab[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << liczbaWywazona(tab[i]+1) << std::endl;
    }

    delete[] tab;
    return 0;
}
