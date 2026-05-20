#include <bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {

    int n = points.size();

    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);

    // Start from node 0
    minDist[0] = 0;

    int totalCost = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;

        // Pick the unvisited node with minimum cost
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        // Update neighbors (all other points)
        for (int v = 0; v < n; v++) {

            if (!visited[v]) {

                int cost = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                minDist[v] = min(minDist[v], cost);
            }
        }
    }

    return totalCost;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << minCostConnectPoints(points) << endl;

    return 0;
}