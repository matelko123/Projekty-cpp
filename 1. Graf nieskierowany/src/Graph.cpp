#include "Graph.hpp"

Graph::Graph() {}
Graph::Graph(std::string filename)
{
    loadData(filename);
}

Graph::~Graph()
{
    clear();
}
void Graph::clear()
{
    for (auto node : graf)
        node.clear();
}

void Graph::loadData(std::string filename)
{
    // File stream
    std::fstream fin;
    fin.open(filename, std::ios::in);
    if (fin.good() == false)
    {
        std::cout << "Something went wrong with read file." << std::endl;
        exit(1);
    }
    std::string line, word;
    int i = 0;
    std::list<int> tmp;

    while (fin.eof() == false)
    {
        i = 0;
        tmp.clear();

        // Get data from file in line
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ';'))
        {
            int val = std::stoi(word);
            if (val == 1)
                tmp.push_back(i);
            i++;
        }
        graf.push_back(tmp);
    }

    fin.close();
}

void Graph::printList(std::list<int> node, int i)
{
    std::cout << i << ": ";

    for (auto const n : node)
        std::cout << " <-> " << n;

    std::cout << std::endl;
}
void Graph::print()
{
    int i = 0;
    for (std::list<int> node : graf)
    {
        printList(node, i++);
    }
}

bool Graph::isCyclic()
{
    const int n = graf.size();
    int w, v, z, i;
    std::list<int> S;

    bool *visited = new bool[n];
    for (int j = 0; j < n; j++)
        visited[j] = false;

    S.push_back(0);
    S.push_back(-1);
    visited[0] = true;
    while (!S.empty())
    {
        w = S.front();
        S.pop_back();
        v = S.front();
        S.pop_back();
        for (auto it = graf[v].begin(); it != graf[v].end(); it++)
        {
            z = *it;
            if (!visited[z])
            {
                S.push_back(z);
                S.push_back(v);
                visited[z] = true;
            }
            else if (z != w)
            {
                delete[] visited;
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool Graph::isConsistent()
{
    int vc = 0, v, u;
    const int n = graf.size();
    std::list<int> S;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++, visited[i] = false);

    S.push_back(0);
    visited[0] = true;

    while (!S.empty())
    {
        S.pop_back();
        v = S.front();

        for (auto it = graf[v].begin(); it != graf[v].end(); it++)
        {
            if (!visited[*it])
            {
                S.push_back(*it);
                visited[*it] = true;
            }
        }
        vc++;
    }

    if (vc == n)
        return true;
    return false;
}
bool Graph::isBipartite()
{
    int vc = 0, v, u;
    const int n = graf.size();
    std::list<int> S, Q;

    int *C = new int[n];
    for (int i = 0; i < n; i++, C[i] = 0);

    for (int i = 0; i < n; i++)
        if (!C[i])
        {
            C[i] = 1;
            Q.push_back(i);

            while (!Q.empty())
            {
                v = Q.front();
                Q.pop_back();
                for (auto it = graf[v].begin(); it != graf[v].end(); it++)
                {
                    if (C[*it] == C[v])
                    {
                        delete[] C;
                        return false;
                    }

                    if (!C[*it])
                    {
                        C[*it] = -C[v];
                        Q.push_back(*it);
                    }
                }
            }
        }

    delete[] C;

    return true;
}
