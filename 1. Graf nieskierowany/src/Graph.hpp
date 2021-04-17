#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <list>
#include <vector>
#include <fstream> // fstream
#include <sstream> // stringstream()

class Graph
{
private:
    std::vector< std::list<int> > graf;
    void printList(std::list<int>, int);
public:
    Graph();
    Graph(std::string);
    ~Graph();
    void loadData(std::string);
    void print();
    void clear();
    bool isClear();
    bool isCyclic();
    bool isConsistent();
    bool isBipartite();
};



#endif // __GRAPH_H__
