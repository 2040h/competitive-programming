// Camino más largo en un DAG
vector<int> distances(n, NEG_INF);
distances[0] = 0;
stack<int> s = topologicalSort(adjList);

while (!s.empty()){
    int u = s.top();
    s.pop();
        
    for (int w : adjList[u]){
        if (distances[w] < distances[u] + 1){
            parents[w] = u;
            distances[w] = distances[u] + 1;
        }
    }
}

if (distances[end] < 0) cout << "No existe camino";

// Cantidad de caminos desde 0 a otros vértices en un DAG
numberOfPaths[0] = 1;
stack<int> s = topologicalSort(adjList);

while (!s.empty()){
    int u = s.top();
    s.pop();
    for (int w : adjList[u]) numberOfPaths[w] = addMod(numberOfPaths[u], numberOfPaths[w], MOD);
}