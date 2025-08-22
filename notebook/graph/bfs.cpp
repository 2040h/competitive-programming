// Algoritmos para Grafos simples
void bfs(int v){
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int w : adjList[u]){
            if (visited[w]) continue;
            visited[w] = true;
            q.push(w);
        }
    }
}

bool isBipartite(int v){
    visited[v] = true;
    team[v] = 1;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int w : adjList[u]){
            if (visited[w] && team[w] == team[u]) return false;
            if (visited[w]) continue;
            visited[w] = true;
            team[w] = team[u] ^ 1;
            q.push(w);
        }
    }

    return true;
}

// ############################################################### //
// Algoritmos para grafos dirigidos

void bfs(int v){
    visited[v] = VISITANDO;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int w : outEdges[u]){
            if (visited[w] == NO_VISITADO){
                visited[w] = VISITANDO;
                q.push(w);
            }
        }
        visited[u] = VISITADO;
    }
}