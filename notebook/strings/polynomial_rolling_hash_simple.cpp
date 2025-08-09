// M = 1e9+7, 991831889, M=1e9+9 (Primo). B=31, B=53, B=9973 (No necesariamente primo).

// Precomputo: O(|s|)
// Query: O(1)

struct HashedString {	
	HashedString(const string &s) : prefix_hash(SIZE(s)+1), potencia(SIZE(s)+1) {
		potencia[0] = 1;
		forsn(i, 1, SIZE(s)+1) { potencia[i] = mulMod(potencia[i-1], B, M); }
		
		prefix_hash[0] = 0;
		forsn(i, 1, SIZE(s)+1) { prefix_hash[i] = addMod(mulMod(prefix_hash[i-1], B, M), (ll)s[i-1], M); }
	}
	
	ll get_hash(int start, int end){ // [start, end]
		return mod(prefix_hash[end + 1] - mulMod(prefix_hash[start], potencia[end - start + 1], M), M);
	}
	
private:
	const ll M = MOD, B = 31  // Cambiar M y B.
	vector<ll> prefix_hash, potencia;
};
