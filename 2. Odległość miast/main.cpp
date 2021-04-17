#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>  //* stringstream

struct road
{
    std::string nazwa;
    unsigned int odleglosc;
    road(){};
    road(std::string n, unsigned int o)
    {
        nazwa = n;
        odleglosc = o;
    }
};

struct miasto
{
    std::string nazwa;
    std::vector<road> next;
    miasto(){};
    miasto(std::string n)
    {
        nazwa = n;
    }
};
// miasto.next -> [ {road.odleglosc, road.nazwa}, {...}, ... ]

int distance(const std::vector<miasto> &miasta, const unsigned int start, miasto &m)
{
    int sum = 0;                    // Sums km
    int count = 0;                  // Count of track
    int idx = start;
    int j = 0;
    int size = miasta.size();
    bool visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    auto cele = miasta[start].next;
    visited[start] = true;

    while (count < 16)
    {
        int min = 10000000,
            min_i = 0;
        for (int i = 0; i < size; i++)
        {
            if (visited[i])
                continue;

            j = (idx < i) ? i - 1 : i;
            if (min > cele[j].odleglosc)
            {
                min_i = i;
                min = cele[j].odleglosc;
            }
        }
        idx = min_i;
        m.next.push_back(road(miasta[idx].nazwa, min));
        visited[idx] = true;
        cele = miasta[idx].next;
        sum += min;
        count++;
    }
    return sum;
}

void loadDataFromFile(const std::string fileName, std::vector<miasto> &miasta)
{
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file || !file.good())
    {
        std::cout << "File error" << std::endl;
        exit(1);
    }

    int size = 0;
    std::string line, word;
    getline(file, line);
    std::stringstream s(line);
    while (getline(s, word, ' '))
    {
        size++;
    }

    // Load cities' name from file (first line)
    file.seekg(0);
    std::string n;
    for (int i = 0; i < size; i++)
    {
        if (!(file >> n))
        {
            std::cout << "Incorrect file. (0: " << i << ")" << std::endl;
            exit(1);
        }
        miasta.push_back(miasto(n));
    }

    unsigned int odleglosc;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!(file >> odleglosc))
            {
                std::cout << "Incorrect file. (" << i + 2 << ": " << j << ")" << std::endl;
                exit(1);
            }
            if (odleglosc == 0)
                continue;

            miasta[i].next.push_back(road(miasta[j].nazwa, odleglosc));
        }
    }
}

void printMiasto(miasto &m)
{
    std::cout << m.nazwa << std::endl;
    for (auto c : m.next)
    {
        std::cout << c.nazwa << ": " << c.odleglosc << "km" << std::endl;
    }
}

void print(std::vector<miasto> &miasta)
{
    for (auto m : miasta)
    {
        printMiasto(m);
    }
}

int main()
{
    std::vector<miasto> miasta;

    loadDataFromFile("dane.txt", miasta);

    // print(miasta);

    miasto m, minim;
    int mini = 1000000;

    int size = miasta.size();

    for (int i = 0; i < size; i++)
    {
        miasto m;
        m.nazwa = miasta[i].nazwa;
        int tmp = distance(miasta, i, m);
        std::cout << "Trasa z " << miasta[i].nazwa << ": " << tmp << "km" << std::endl;

        if (mini > tmp)
        {
            mini = tmp;
            minim = m;
        }
    }

    std::cout << std::endl
              << "Najkrotsza trasa jest z ";
    printMiasto(minim);
    std::cout << mini << std::endl;

    return 0;
}