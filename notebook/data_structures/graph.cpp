struct Graph {
    int m;
    vector<bool> visited;
    vector<vector<int>> adjList;
    vector<int> parent;

    Graph(int size): m(size){
        adjList.resize(m);
        visited.resize(m, false);
        parent.resize(m, UNDEFINED);
    }

    void addEdge(int u, int v){
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
};

enum Estado{
    NO_VISITADO,
    VISITANDO,
    VISITADO
};

struct DirectedGraph {
    int m; 
    vector<vector<int>> outEdges; 
    vector<vector<int>> inEdges; 
	vector<Estado> visited;

    DirectedGraph(int size) : m(size) {
        outEdges.resize(m);
        inEdges.resize(m);
        visited.resize(m, NO_VISITADO);
    }

    // Edge u -> v
    void addEdge(int u, int v) {
        outEdges[u].pb(v);
        inEdges[v].pb(u);
    }
};
