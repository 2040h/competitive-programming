// En general: O(n^2 * m)
// Matching en grafo bipartito: O(sqrt(n)*m) [Las constantes no son optimas]

using flow_type = ll;  // Si se cambia por double o simil cambiar las comparaciones.
struct Edge { int from int to, rev; flow_type f, cap; };  // rev me ayuda a acceder a la arista que vuelve, me da el indice en G[u].

struct Dinic {
    int n, t_; vector<vector<Edge>> G;
    
    Dinic(int N) : n(N), G(N), dist(N) {}
    
    void add_edge(int u, int v, flow_type cap, bool directed = true) {
        G[u].pb({u, v, SIZE(G[v]), 0, cap});
        G[v].pb({v, u, SIZE(G[u])-1, directed ? 0 : cap, 0}); // Use cap instead of 0 if bidirectional
    }
    
    flow_type max_flow(int s, int t) {  // Dinic.
        t_ = t; flow_type ans = 0;
        while (bfs(s, t)) while (flow_type dl = dfs(s, numeric_limits<flow_type>::max())) ans += dl;
        return ans;
    }
    
private:
    vi dist;  // level graph
    vi W;  // work, ptr, optimizacion.
    
    bool bfs(int s, int t) {
        W.assign(n, 0); dist.assign(n, UNDEFINED); dist[s] = 0;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Edge &e : G[u]) if (dist[e.to] == UNDEFINED && e.f < e.cap)
                dist[e.to] = dist[u] + 1, q.push(e.to);
        }
        return dist[t] != UNDEFINED;
    }
    
    flow_type dfs(int u, flow_type f) {
        if (u == t_ || f == 0) return f;
        for (int &i = W[u]; i < SIZE(G[u]); i++) {
            Edge &e = G[u][i]; int v = e.to;
            if (e.cap <= e.f || dist[v] != dist[u] + 1) {continue;}
            flow_type df = dfs(v, min(f, e.cap - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }
};
