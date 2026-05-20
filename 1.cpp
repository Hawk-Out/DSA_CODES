#include <bits/stdc++.h>
using namespace std;

int main() {

    int V, E;

    cin >> V >> E;

    vector<pair<int,int>> adj[V];

    // Input graph
    for(int i = 0; i < E; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min Heap
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> visited(V, false);

    int mstWeight = 0;

    // Start from node 0
    pq.push({0, 0});

    while(!pq.empty()) {

        auto p = pq.top();

        pq.pop();

        int weight = p.first;
        int node = p.second;

        // Skip if already visited
        if(visited[node])
            continue;

        visited[node] = true;

        mstWeight += weight;

        // Visit neighbors
        for(auto &edge : adj[node]) {

            int neighbor = edge.first;

            int edgeWeight = edge.second;

            if(!visited[neighbor]) {

                pq.push({edgeWeight, neighbor});
            }
        }
    }

    cout << "Minimum Spanning Tree Weight = "
         << mstWeight << endl;

    return 0;
}