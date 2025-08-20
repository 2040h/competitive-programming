// Algoritmos para Grafos simples

void dfs(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        parent[u] = v;
        if (!visited[u]) dfs(u);
    }
}

// Encontrar ciclo en un grafo simple
void defineParentFrom(int v){
    visited[v] = true;
    for (int u : adjList[v]){
        if (!visited[u]){
            parent[u] = v;
            defineParentFrom(u);
        }
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

// Antes tengo que haber encontrado un ciclo con findCycle(i)
vector<int> getCycle(){
    int currentVertex = cycle_end;
    while (currentVertex != cycle_start){
        cycle.pb(currentVertex);
        currentVertex = parent[currentVertex];
    }

    cycle.pb(cycle_start);
    reverse(all(cycle));
    cycle.pb(cycle_start);
    return cycle;
}

// ###########################################################################
// Algoritmos para grafos dirigidos

// Aca devuelve ciclos de longitud 2
int findCycle(int v){
    visited[v] = VISITANDO;
    
    for (int u : outEdges[v]){
        if (visited[u] == VISITANDO) {
            parent[u] = UNDEFINED;
            return v;
        }
        
        if (visited[u] == NO_VISITADO){
            parent[u] = v;
            int possibleCycle = findCycle(u);
            if (possibleCycle != UNDEFINED) return possibleCycle;
        }
    }

    visited[v] = VISITADO;
    return UNDEFINED;
}

// v tiene que ser el resultado de findCycle(i) y v != UNDEFINED
vector<int> buildCycle(int startCycle){
    vector<int> cycle;
    int currentVertex = startCycle;
    while (currentVertex != UNDEFINED){
        cycle.pb(currentVertex);
        currentVertex = parent[currentVertex];
    }

    reverse(all(cycle));
    cycle.pb(startCycle);
    return cycle;
}
