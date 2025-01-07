#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    vector<vector<int>> adjMatrix;

public:
    Graph(int n)
    {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdges(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void removeEdges(int u ,int v)
    {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
    }


    void addVertex()
    {
        int n = adjMatrix.size();
        adjMatrix.push_back(vector<int>(n,0));

        for(auto& rows : adjMatrix)
        {
            rows.push_back(0);
        } 
    }

    void removeVertex(int vertex)
    {
        int n = adjMatrix.size();

        if(vertex >= n)
        {
            cout<<" Vertex dosn't exist.";
            return;
        }

        adjMatrix.erase(adjMatrix.begin() + vertex);

        for(auto& rows : adjMatrix)
        {
            rows.erase(rows.begin() + vertex);
        }

    }

    void print()
    {
        cout << "Adjency Matrix\n";
        int n = adjMatrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adjMatrix[i][j]<<" ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n = 4;

    Graph g(n);

    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 3);
    g.addEdges(2, 3);

    g.removeEdges(0,1);

    g.addVertex();
    g.addEdges(0,4);
    g.removeVertex(1);
    g.print();

}
