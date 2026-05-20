//krushkal
#include <bits/stdc++.h>
using namespace std;

struct Edge {

    int u, v, weight;
};

int parent[1000];
int rankArr[1000];

bool compare(Edge a, Edge b) {

    return a.weight < b.weight;
}

int findSet(int x) {

    if(parent[x] != x)

        parent[x] = findSet(parent[x]);

    return parent[x];
}

void unionSet(int x, int y) {

    int px = findSet(x);
    int py = findSet(y);

    if(px == py)
        return;

    if(rankArr[px] < rankArr[py])

        parent[px] = py;

    else if(rankArr[px] > rankArr[py])

        parent[py] = px;

    else {

        parent[py] = px;

        rankArr[px]++;
    }
}

int kruskal(int V, int E, vector<Edge>& edges) {

    for(int i = 0; i < V; i++) {

        parent[i] = i;

        rankArr[i] = 0;
    }

    sort(edges.begin(), edges.end(), compare);

    int mstWeight = 0;
    int edgeCount = 0;

    for(int i = 0; i < E; i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if(findSet(u) != findSet(v)) {

            unionSet(u, v);

            mstWeight += w;

            edgeCount++;

            if(edgeCount == V - 1)
                break;
        }
    }

    return mstWeight;
}

int main() {

    int V, E;

    cin >> V >> E;

    vector<Edge> edges(E);

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << "Minimum Spanning Tree Weight = " << kruskal(V, E, edges) << endl;

    return 0;
}