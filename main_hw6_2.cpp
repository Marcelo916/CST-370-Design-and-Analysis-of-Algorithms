/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_2.
 *     When you finish the development, download this file and submit to Canvas
 *     according to the submission instructions.
 *
 *     Please DO NOT change the name of the main procecure "main()"
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: Floyd's Algorithm
 * Abstract: This program implements the Floyd Algorithm to display all-pairs shortest
             paths. The first line indicates the number of vertices in the input graph.
             The following lines present the distances among the vertices. The value -1 
             indicates infinity. 
 * Name: Marcelo Villalobos Diaz
 * Date: 02/19/2025
 */

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // Representation of infinity

void floydW(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph;

    // Floyd's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Prints the final distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) 
                cout << "-1";
            else 
                cout << dist[i][j];

            if (j < n - 1)
                cout << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    // Reads the input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            cin >> value;
            if (value == -1) 
                graph[i][j] = INF; // Converts -1 to INF
            else 
                graph[i][j] = value;
        }
    }

    floydW(graph, n);
    
    return 0;
}

