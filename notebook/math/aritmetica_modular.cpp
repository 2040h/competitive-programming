ll mod(ll a, ll m = MOD){
	ll res = ((a % m) + m) % m;
	return res;
}

ll addMod(ll a, ll b, ll m = MOD){
    ll res = ((a % m) + (b % m)) % m;
    return res;
}
 
ll mulMod(ll a, ll b, ll m = MOD){
	ll res = (ll) a*b;
	res %= m;
    return res;
}
 
ll binPowMod(ll base, ll exp, ll m = MOD){
    if (exp == 0) return 1;
    
    ll a = binPowMod(base, exp/2, m);
    ll res = mulMod(a, a, m);
    
    if (exp % 2 == 1) res = mulMod(res, base, m);
    return res;
}
 
ll divideMod(ll a, ll b, ll m = MOD){
    ll res = mulMod(a % m, binPowMod(b, m-2, m) % m, m) % m;
    return res;
}

void calcularFactorial(ll n, ll m = MOD){
	fact[0] = 1;
	forsn(i, 1, n+1) fact[i] = mulMod(fact[i-1], i, m);
}

ll combinatorial_func(ll n, ll k, ll m = MOD){
	return divideMod(fact[n], mulMod(fact[k], fact[n-k], m), m);
}
