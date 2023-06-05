/*You have a business with several offices; you want to lease phone lines to connect them up with
each other; and the phone company charges different amounts of money to connect different pairs
of cities. You want a set of lines that connects all your offices with a minimum total cost. Solve
the problem by suggesting appropriate data structures.*/

#include <iostream>
using namespace std;
#define row 10
#define col 10
#define INF 9999

class MSTree
{
    int graph[row][col], nodes;

public:
    void createGraph();
    void primsAlgo();
};

void MSTree::createGraph()
{
    int i, j;
    cout << "Enter Total number of Offices: ";
    cin >> nodes;
    cout << "\n Enter Adjacency Matrix: ";
    for (i = 0; i < nodes; i++)
    {
        for (j = i; j < nodes; j++)
        {
            cout << "Enter Distance between " << i << " and " << j << endl;
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }
}

void MSTree::primsAlgo()
{
    int selected[row], i, j, ne = 0;
    int zero = 0, one = 1, x, y, min = 0;
    int cost = 0;

    for (i = 0; i < nodes; i++)
    {
        selected[i] = zero;
    }
    selected[0] = one;
    while (ne < nodes - 1)
    {
        min = INF;
        for (i = 0; i < nodes; i++)
        {
            if (selected[i] == one)
            {
                for (j = 0; j < nodes; j++)
                {
                    if (selected[j] == zero)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = one;
        cout << "\n"
             << x << "--->" << y;
        cost += graph[x][y];
        ne++;
    }

    cout << "Cost: " << cost << endl;
}

int main()
{
    MSTree obj;
    cout << "\n Prims ALgorithm to connect several offices \n";
    obj.createGraph();
    obj.primsAlgo();
    return 0;
}