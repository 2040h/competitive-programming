// Versión con BFS

int diameterVertex;

int maxDepth(int v){
    visited.assign(m, false);
    distances.assign(m, INF);
    distances[v] = 0;
    visited[v] = true;

    queue<int> q;
    q.push(v);

    int res = 0;

    while (!q.empty()){
        int u = q.front(); q.pop();
        diameterVertex = u;

        for (int w : adjList[u]){
            if (!visited[w]){
                q.push(w);
                distances[w] = distances[u] + 1;
                visited[w] = true;
                res = max(res, distances[w]);
            }
        }
    }

    return res;
}

int diameterTree(){
    maxDepth(0);
    int diameterVertex1 = diameterVertex;
    int diameterLength = maxDepth(diameterVertex1);
    int diameterVertex2 = diameterVertex;
    return diameterLength;
}

// ###################################################################################################
// Versión con DP
void dfs(int v, int currentParentOfV){
    vector<int> branchsLength;
    
    for (int u : adjList[v]){
        if (u == currentParentOfV) continue;
        dfs(u, v);
        branchsLength.pb(longestBranchFrom[u]);
    }

    longestBranchFrom[v] = 0;
    sort(all(branchsLength)); // Esto se puede hacer en O(n) buscando los dos máximos 
    if (SIZE(branchsLength) > 0) longestBranchFrom[v] = 1 + branchsLength[SIZE(branchsLength)-1];
    if (SIZE(branchsLength) > 1) longestPathThrough[v] = branchsLength[SIZE(branchsLength)-1] + 2 + branchsLength[SIZE(branchsLength)-2];
    lengthDiameter = max(lengthDiameter, max(longestBranchFrom[v], longestPathThrough[v]));
}