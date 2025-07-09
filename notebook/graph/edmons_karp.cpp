ll capacity[MAX_N][MAX_N];
 
ll bfs(int s, int t, vector<int>& parent, vector<vector<int>> &ady) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
 
    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
 
        for (int next : ady[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
 
    return 0;
}
 
ll maxflow(int s, int t, vector<vector<int>> &ady) {
    ll flow = 0;
    vector<int> parent(n);
    ll new_flow;
 
    while (new_flow = bfs(s, t, parent, ady)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}