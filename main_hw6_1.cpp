/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file and submit to Canvas
 *     according to the submission instructions.
 *
 *     Please DO NOT change the name of the main procedure "main()"
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: Coin Collection
 * Abstract: This program collects the maximum number of coins on an n x m board.
             The first line indicates that the board has n rows and m columns. The
             configuration is presented in the second line. The number 1 indicates that 
             there is a coin on the cell. 
 * Name: Marcelo Villalobos Diaz
 * Date: 02/19/2025
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Finds the max number of coins and path
void findMaxAndPath(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    dp[0][0] = grid[0][0];

    // Fills first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
        parent[0][j] = {0, j-1};
    }

    // Fills first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
        parent[i][0] = {i-1, 0};
    }

    // Fills rest of the table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
                parent[i][j] = {i-1, j};
            } else {
                dp[i][j] = dp[i][j-1] + grid[i][j];
                parent[i][j] = {i, j-1};
            }
        }
    }

    cout << "Max coins:" << dp[n-1][m-1] << endl;

    // Backtrack to find the path
    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;
    
    while (i != 0 || j != 0) {
        path.push_back({i+1, j+1});
        auto [pi, pj] = parent[i][j];
        i = pi;
        j = pj;
    }
    path.push_back({1, 1});
    reverse(path.begin(), path.end());

    // Prints path
    cout << "Path:";
    for (size_t i = 0; i < path.size(); i++) {
        cout << "(" << path[i].first << "," << path[i].second << ")";
        
        if (i != path.size() - 1) {
            cout << "->";
        }
    }

    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    // Reads board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    findMaxAndPath(grid, n, m);
    
    return 0;
}

