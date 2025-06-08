void dfs(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        parent[u] = v;
        if (!visited[u]) dfs(u);
    }
}

// Devuelve vértice en el que empieza un ciclo. Si no encuentra ninguno, retorna UNDEFINED
// Llamarla ya habiendo definido los padres
int findCycle(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        if (u == parent[v]) continue; 
        if (visited[u]) return u;
        int cycle = dfs(u);
        if (cycle != UNDEFINED) return cycle;
    }

    return UNDEFINED;
}

// Idem anterior, pero para grafo dirigido. Acá devolvemos ciclos de longitud 2
int findCycle(int v){
    visited[v] = VISITANDO;
    
    for (int u : outEdges[v]){
        if (visited[v] == VISITANDO) return v;
        if (visited[v] == NO_VISITADO){
            int possibleCycle = findCycle(u);
            if (possibleCycle != UNDEFINED) return possibleCycle;
        }
    }

    visited[v] = VISITADO;
    return UNDEFINED;
}