// Precomputo: O(ht*|s|)
// Query: O(ht)

struct HashedString {	
	HashedString(const string &s) : prefix_hash(ht_size, vector<ll>(SIZE(s)+1)) {
		forn(ht, ht_size){
			const ll M = M_vec[ht], B = B_vec[ht];
			
			if(potencia.empty()) { potencia.assign(ht_size, vector<ll>(1, 1)); }
			while(SIZE(potencia[ht]) <= SIZE(s)) { potencia[ht].pb(mulMod(potencia[ht].back(), B, M)); }
			
			prefix_hash[ht][0] = 0;
			forsn(i, 1, SIZE(s)+1) { prefix_hash[ht][i] = addMod(mulMod(prefix_hash[ht][i-1], B, M), (ll)s[i-1], M); }
		}
	}
	
	vector<ll> get_hash(int start, int end){ // [start, end]
		vector<ll> hash_res(ht_size);
		forn(ht, ht_size){
			const ll M = M_vec[ht];
			hash_res[ht] = mod(prefix_hash[ht][end + 1] - mulMod(prefix_hash[ht][start], potencia[ht][end - start + 1], M), M);
		}
		return hash_res;
	}
	
private:
	inline static const vector<ll> M_vec = {MOD, 991831889};
	inline static vector<ll> B_vec = [](){
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		vector<ll> bases; bases.reserve(SIZE(M_vec));
		for(ll M : M_vec){
			const ll B = uniform_int_distribution<ll>(0.1 * M, 0.9 * M)(rng);
			bases.pb(B);			
		}
		return bases;
	}();
	const int ht_size = SIZE(M_vec);
	vv<ll> prefix_hash;
	inline static vv<ll> potencia;
};
