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
	const ll M = MOD, B = 31;  // Cambiar M y B.
	vector<ll> prefix_hash, potencia;
};

// ######################################################################################################
// Implementación alternativa

powers.resize(maxPower+1, 1); invPowers.resize(maxPower+1, 1);
forsn(i, 1, maxPower+1) powers[i] = mulMod(powers[i-1], p, m);
forsn(i, 1, maxPower+1) invPowers[i] = binPowMod(powers[i], m-2, m);

struct HashString{
	ll p, m, n; // primo, mod, SIZE(s)
	vector<char> s;
	const vl *powers;
	const vl *invPowers;
	vl prefixHash;
	
	ll getValue(char c){return c - 'a' + 1;}

	HashString(){}
	HashString(ll P, ll M, const vector<char> &S, const vl &Powers, const vl &InvPowers) : p(P), m(M), n(SIZE(S)), s(S), powers(&Powers), invPowers(&InvPowers){
		prefixHash.resize(n+1, 0);
		forsn(i, 1, n+1) prefixHash[i] = addMod(prefixHash[i-1], mulMod(getValue(s[i-1]), (*powers)[i-1], m), m);
	}
	
	ll get_hash(int start, int end){ // [start, end]
		ll res = addMod(prefixHash[end+1], (-1)*prefixHash[start], m); // res = hash[0, ..., end] - hash[0, ..., start-1] 
		res = mulMod(res, (*invPowers)[start], m); // res /= 2^start
		return res;
	}
};