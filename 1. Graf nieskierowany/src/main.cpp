#include <iostream>
#include "Graph.hpp"

int main()
{
    Graph graf("example.csv");
    // graf.print();
    bool a = graf.isCyclic();
    if (!a)
        std::cout << "Graf jest lasem" << std::endl;
    else
        std::cout << "Graf nie jest lasem" << std::endl;

    bool b = graf.isConsistent();
    if (b)
        std::cout << "Graf jest spójny" << std::endl;
    else
        std::cout << "Graf nie jest spójny" << std::endl;

    if (a && b)
        std::cout << "Graf jest drzewem" << std::endl;
    else
        std::cout << "Graf nie jest drzewem" << std::endl;

    if (graf.isBipartite())
        std::cout << "Graf jest dwudzielny" << std::endl;
    else
        std::cout << "Graf nie jest dwudzielny" << std::endl;

    return 0;
}
