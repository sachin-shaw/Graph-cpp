#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n)
{
    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];

    for (int i = 1; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    visited[0] = false; // check this line need or not
    weight[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // Find min vertex
        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;
        // Explore un-visited neighbours
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    cout << "output answer" << endl;
    for (int i = 1; i < n; i++)
    {
        if (i < parent[i])
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
        else
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    prims(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}

/*
6 11
0 1 2
1 3 1
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6
*/

/*
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5
*/