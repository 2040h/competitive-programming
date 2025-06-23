// Camino más largo en un DAG desde 0
vector<int> distances(n, NEG_INF);
distances[0] = 0;
vector<ll> s = topologicalSort(adjList);

for (int v : s){
    for (int u : adjList[v]){
        if (distances[u] < distances[v] + 1){
            parent[u] = v;
            distances[u] = distances[v] + 1;
        }
    }
}

if (distances[end] < 0) cout << "No existe camino";

// Cantidad de caminos desde 0 a otros vértices en un DAG
vector<ll> numberOfPaths(n, 0);
numberOfPaths[0] = 1;

for (int v : orden){
    for (int u : adjList[v]) numberOfPaths[u] = addMod(numberOfPaths[u], numberOfPaths[v], MOD);
}
