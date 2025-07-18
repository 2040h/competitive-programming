// Hierholzer: O(n+m)

// Condicion de ciclo/camino euleriano en grafos:
// (1) Conexo.
// (2) Todos los vertices tienen grafo par (ciclo) o hay exactamente dos vertices de grado impar y el resto par (camino).
// En este ultimo caso siempre se debe empezar en el vertice de grado impar y el camino terminara en el otro vertice de grado impar.

// Condicion de ciclo/camino euleriano en digrafos:
// (1) Conexo.
// (2) Para todo v en V, in_deg[v] == out_deg[v] (ciclo) o se cumple eso para todos los vertices excepto 2: u, w in_deg[u]+1 == out_deg[u] y in_deg[w] == out_deg[w]+1 (camino).
// En este ultimo caso siempre se debe empezar en el vertice con mayor grado de salida (u) y el camino terminara en el otro vertice con mayor grado de entrada (w).

// Para ver si es conexo, una vez que ya vi (2), puedo correr Hierholzer y comprobar que la longitud del camino es igual a |E|+1.

// ady[i][j] = <indice nodo, id de arista>. En caso de grafo ponerle el mismo id a ambas direcciones. NOTA: El dfs es destructivo para ady.
using indice_nodo_t = int;

void euler_dfs(indice_nodo_t v, vector<vector<pair<indice_nodo_t, int>>> &ady, vector<bool> &aristas_visitadas, vector<indice_nodo_t> &camino){
	while(!ady[v].empty()){
		auto [u, id_e] = ady[v].back();
		ady[v].pop_back();
		if(!aristas_visitadas[id_e]){
			aristas_visitadas[id_e] = true;
			euler_dfs(u, ady, aristas_visitadas, camino);
		}
	}
	camino.pb(v);
}
