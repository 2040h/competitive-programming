// Devuelve true sii existe un ciclo en G.
// Si no existe ciclo, en orden queda almacenado un orden topologico de G.
bool toposort(vector<vector<int>> &ady, vector<int> &orden){
	orden.clear();
	vector<int> in_deg(SIZE(ady), 0);
	
	for(int v=0; v<SIZE(ady); v++){
		for(const auto u : ady[v]){
			in_deg[u]++;
		}
	}
	
	queue<int> q; // Si usamos min priority_queue podemos obtener el orden lexicografico más chico
	for(int v=0; v<SIZE(ady); v++){
		if(in_deg[v] == 0){
			q.push(v);
		}
	}
	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		orden.pb(v);
		
		for(auto u : ady[v]){
			in_deg[u]--;
			if(in_deg[u] == 0){
				q.push(u);
			}
		}
	}
	
	return SIZE(orden) != SIZE(ady);  // Retorna true sii hay un ciclo.
}
