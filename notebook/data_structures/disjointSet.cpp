struct DisjointSet{
    vector<ll> parent, rnk;
    ll numOfComponents;

    DisjointSet(ll n){
        rnk.assign(n, 0);
        forn(i, n) {parent.pb(i);}
        numOfComponents = n;
    }

    ll findSet(ll x){
        if(parent[x]!=x) {parent[x] = findSet(parent[x]);}
        return parent[x];
    }

    void unionSet(ll x, ll y){
        // Encontrar los representantes del conjunto.
        x = findSet(x); y = findSet(y);

        // Si los conjuntos son disjuntos:
        if (x != y){
            // Pongo al que tiene menos rango por debajo del de mayor rango.
            if (rnk[x] < rnk[y]){
                parent[x] = y;
            } else if (rnk[x] > rnk[y]){
                parent[y] = x;
            } else {  // Si tienen el mismo rango, incremento del rango.  (rnk[x] == rnk[y])
                parent[y] = x;
                rnk[x]++;
            }
            numOfComponents--;
        }
    }

    bool same(ll x, ll y){
        return findSet(x) == findSet(y);
    }
};
