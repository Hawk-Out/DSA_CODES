#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> parent, rankArr;

public:

    DisjointSet(int n) {

        parent.resize(n);
        rankArr.resize(n, 0);

        for(int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x) {

        if(parent[x] != x) {

            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    // Union by Rank
    void unionSets(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
            return;

        if(rankArr[rootX] < rankArr[rootY]) {

            parent[rootX] = rootY;
        }

        else if(rankArr[rootX] > rankArr[rootY]) {

            parent[rootY] = rootX;
        }

        else {

            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
};

int countCompleteComponents(int n, vector<vector<int>>& edges) {

    DisjointSet ds(n);

    // Step 1: Create components
    for(vector<int> &edge : edges) {

        ds.unionSets(edge[0], edge[1]);
    }

    // Step 2: Count nodes in each component
    vector<int> nodeCount(n, 0);

    for(int i = 0; i < n; i++) {

        int root = ds.find(i);

        nodeCount[root]++;
    }

    // Step 3: Count edges in each component
    vector<int> edgeCount(n, 0);

    for(vector<int> &edge : edges) {

        int root = ds.find(edge[0]);

        edgeCount[root]++;
    }

    // Step 4: Check complete components
    int completeComponents = 0;

    for(int i = 0; i < n; i++) {

        // Process only roots
        if(ds.find(i) == i) {

            int nodes = nodeCount[i];

            int edgesNeeded = nodes * (nodes - 1) / 2;

            if(edgeCount[i] == edgesNeeded) {

                completeComponents++;
            }
        }
    }

    return completeComponents;
}

int main() {

    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++) {

        int u, v;

        cin >> u >> v;

        edges.push_back({u, v});
    }

    int ans = countCompleteComponents(n, edges);

    cout << "Number of Complete Components: " << ans << endl;

    return 0;
}