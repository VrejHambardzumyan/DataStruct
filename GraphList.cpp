#include <iostream>
#include <list>
#include <map>

using namespace std;

class Graph
{
    map<int, list<int>> adjList;

public:
    void addEdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void removeEdges(int u, int v)
    {
        adjList[u].remove(v);
        adjList[v].remove(u);
    }

    void addVertex(int vertex)
    {
        if (adjList.find(vertex) == adjList.end())
        {
            adjList[vertex] = list<int>();
            cout << "Vertex " << vertex << " added.\n";
        }
        else
        {
            cout << "Vertex " << vertex << " already exists.\n";
        }
    }

    void removeVertex(int vertex)
    {
        if (adjList.find(vertex) == adjList.end())
        {
            cout << "Vertex " << vertex << " does not exist.\n";
            return;
        }

        for (auto neighbor : adjList[vertex])
        {
            adjList[neighbor].remove(vertex);
        }

        adjList.erase(vertex);

        cout << "Vertex " << vertex << " removed.\n";
    }

    void print()
    {
        cout << "Adjency list for the Graph \n";
        for (auto i : adjList)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdges(1, 0);
    g.addEdges(2, 0);
    g.addEdges(1, 2);

    g.print();
    
    g.addVertex(3);

    // Add edges for the new vertex
    g.addEdges(3, 1);
    g.addEdges(3, 2);

    cout << "\nAfter adding vertex 3:\n";
    g.print();

    // Remove an edge
    g.removeEdges(1, 2);
    cout << "\nAfter removing edge between 1 and 2:\n";
    g.print();

    // Remove a vertex
    g.removeVertex(3);
    cout << "\nAfter removing vertex 3:\n";
    g.print();
}