//rank and path compression 
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> parent, rank;

public:

    // Constructor
    DisjointSet(int n) {

        parent.resize(n);

        rank.resize(n, 0);

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

        if(rank[rootX] < rank[rootY]) {

            parent[rootX] = rootY;
        }

        else if(rank[rootX] > rank[rootY]) {

            parent[rootY] = rootX;
        }

        else {

            parent[rootY] = rootX;

            rank[rootX]++;
        }
    }

    // Check Connectivity
    bool connected(int x, int y) {

        return find(x) == find(y);
    }
};

int main() {

    DisjointSet ds(8);

    ds.unionSets(0, 1);

    ds.unionSets(2, 3);

    ds.unionSets(0, 2);

    ds.unionSets(5, 6);

    ds.unionSets(6, 7);

    cout << ds.connected(0, 3) << endl;

    cout << ds.connected(0, 5) << endl;

    cout << ds.connected(5, 7) << endl;

    ds.unionSets(4, 5);

    cout << ds.connected(4, 7) << endl;

    return 0;
}

/*int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    DisjointSet ds(n);

    int unions;

    cout << "Enter number of unions: ";
    cin >> unions;

    cout << "Enter unions (u v):" << endl;

    for(int i = 0; i < unions; i++) {

        int u, v;

        cin >> u >> v;

        ds.unionSets(u, v);
    }

    int queries;

    cout << "Enter number of queries: ";
    cin >> queries;

    cout << "Enter queries (u v):" << endl;

    for(int i = 0; i < queries; i++) {

        int u, v;

        cin >> u >> v;

        cout << ds.connected(u, v) << endl;
    }

    return 0;
}*/