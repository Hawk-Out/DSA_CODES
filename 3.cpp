//Cycle Detection 
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> parent, rank;

public:

    DisjointSet(int n) {

        parent.resize(n);

        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    int find(int x) {

        if(parent[x] != x) {

            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

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
};

struct Edge {

    int u, v;
};

bool hasCycle(int V, vector<Edge>& edges) {

    DisjointSet ds(V);

    for(auto &edge : edges) {

        int u = edge.u;

        int v = edge.v;

        // Cycle Exists
        if(ds.find(u) == ds.find(v)) {

            return true;
        }

        ds.unionSets(u, v);
    }

    return false;
}

int main() {

    vector<Edge> edges = {

        {0,1},
        {1,2},
        {2,0}
    };

    cout << hasCycle(3, edges);
    /* int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v):" << endl;

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u >> edges[i].v;
    }

    if(hasCycle(V, edges)) {

        cout << "Cycle Detected!" << endl;

    } else {

        cout << "No Cycle Found!" << endl;
    }

    return 0;*/

    return 0;
}