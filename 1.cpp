// BASIC Code
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;

public:

    // Constructor
    DisjointSet(int n) {

        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Basic Find
    int find(int x) {

        if(parent[x] == x)
            return x;

        return find(parent[x]);
    }

    // Basic Union
    void unionSets(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

int main() {

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    DisjointSet ds(n);

    cout << "Enter number of union operations: ";
    cin >> m;

    cout << "Enter pairs (u v):\n";

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        ds.unionSets(u, v);
    }

    int q;
    cout << "Enter number of find queries: ";
    cin >> q;

    cout << "Enter elements to find parent:\n";

    for(int i = 0; i < q; i++) {

        int x;
        cin >> x;

        cout << "Root of " << x << " = " << ds.find(x) << endl;
    }

    return 0;
}