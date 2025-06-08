// Algoritmos para Grafos simples

void dfs(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        parent[u] = v;
        if (!visited[u]) dfs(u);
    }
}

bool findCycle(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        if (u == parent[v]) continue; 
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        
        if (findCycle(u)) return true;
    }

    return false;
}

// ###########################################################################
// Algoritmos para grafos dirigidos

// Acá devuelve ciclos de longitud 2
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

