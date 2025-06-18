enum Color {WHITE, GREY, BLACK};  // Sin visitar / en proceso / Procesado.

// Devuelve true si encuentra un ciclo.
bool tdfs(ll v, const vector<vector<ll>> &ady, vector<Color> &color, vector<ll> &orden){
    color[v] = GREY;

    for(auto u : ady[v]){
        if(color[u] == GREY){  // Si encuentra un nodo en proceso, hay un ciclo.
            return true;
        }
        else if (color[u] == WHITE){  // Si encuentra un nodo no visitado, realiza DFS.
            if(tdfs(u, ady, color, orden)) return true;
        }
    }

    orden.pb(v);
    color[v] = BLACK;
    return false;
}

// Devuelve true sii existe un ciclo en G.
// Si no existe ciclo, en orden queda almacenado un orden topologico de G.
bool toposort(vector<vector<ll>> &ady, vector<ll> &orden){
    vector<Color> color(SIZE(ady), WHITE);
    orden.clear();

    forn(v, SIZE(ady)){
        if (color[v] == WHITE && tdfs(v, ady, color, orden)) return true;
    }

    reverse(all(orden));
    return false;
}
