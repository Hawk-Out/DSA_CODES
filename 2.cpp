#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> parent, rankArr;

public:

    DisjointSet(int n) {

        parent.resize(n + 1);
        rankArr.resize(n + 1, 0);

        for(int i = 0; i <= n; i++) {

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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    int n = edges.size();

    DisjointSet ds(n);

    for(vector<int> &edge : edges) {

        int u = edge[0];
        int v = edge[1];

        // Cycle detected
        if(ds.find(u) == ds.find(v)) {

            return {u, v};
        }

        ds.unionSets(u, v);
    }

    return {};
}

int main() {

    int n;

    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < n; i++) {

        int u, v;

        cin >> u >> v;

        edges.push_back({u, v});
    }

    vector<int> ans = findRedundantConnection(edges);

    cout << "Redundant Edge: ";

    cout << ans[0] << " " << ans[1];

    return 0;
}