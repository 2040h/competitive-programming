struct SegmentTree{
    int n;
    vl A, B;

    SegmentTree(int N, vl &a) : n(N), A(a){
        B.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int v, int tl, int tr){ // Vértice actual y rango [tl, tr] que indica este vértice
        if (tl == tr) B[v] = A[tl]; // Cuando llego a una hoja, el valor es el mismo elemento
        else {
            int tm = (tl + tr)/2;
            // Construyo el hijo izquierdo y el derecho
            build(2*v, tl, tm);
            build(2*v+1, tm+1, tr);
            // B[v] = f(B[2*v], B[2*v+1]);
            B[v] = B[2*v] + B[2*v+1];
        }
    }

    // query(1, 0, n-1, l, r)
    ll query(int v, int tl, int tr, int l, int r){
        if (l > r) return 0; // Elemento neutro de las queries
        if (l == tl && r == tr) return B[v];
        int tm = (tl+tr)/2;
        // res = f(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r))
        return query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val){
        if (tl == tr) B[v] = new_val;
        else {
            int tm = (tl + tr)/2;
            if (pos <= tm) update(2*v, tl, tm, pos, new_val);
            else update(2*v+1, tm+1, tr, pos, new_val);
            // B[v] = f(B[2*v], B[2*v+1]);
            B[v] = B[2*v] + B[2*v+1];
        }
    }
};