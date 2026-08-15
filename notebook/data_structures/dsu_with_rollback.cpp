struct DisjointSetWithRollback{
	struct Change {int child, parent, oldParentSize;};
	
    vi parent, sz;
    int numOfComponents;
    vector<Change> history;

    DisjointSetWithRollback(int n) : sz(n, 1), numOfComponents(n){
        forn(i, n) {parent.pb(i);}
    }

    int findSet(int x){
		return x == parent[x] ? x : findSet(parent[x]);
    }

    void unionSet(int x, int y){
        x = findSet(x); y = findSet(y);
		if(x == y){return;}    
		
        if(sz[x] < sz[y]) swap(x, y);
		history.pb({y, x, sz[x]});
		
		parent[y] = x;
		sz[x] += sz[y];	
        numOfComponents--;
    }

    bool same(int x, int y) {return findSet(x) == findSet(y);}
    
    int snapshot() {return SIZE(history);}
    
    void rollback(int snap){
		while(SIZE(history) > snap){
			Change c = history.back(); history.pop_back();
			parent[c.child] = c.child;
			sz[c.parent] = c.oldParentSize;
			numOfComponents++;
		}
	}
};
