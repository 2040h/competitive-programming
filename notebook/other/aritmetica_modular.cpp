int addMod(int a, int b, int m = MOD){
    int res = ((a % m) + (b % m)) % m;
    return res;
}
 
int mulMod(int a, int b, int m = MOD){
	ll resLL = (ll) a*b;
	resLL %= m;
	int res = (int) resLL;
    return res;
}
 
int binPowMod(int base, int exp, int m = MOD){
    if (exp == 0) return 1;
    
    int a = binPowMod(base, exp/2, m);
    int res = mulMod(a, a, m);
    
    if (exp % 2 == 1) res = mulMod(res, base, m);
    return res;
}
 
int divideMod(int a, int b, int m = MOD){
    int res = mulMod(a % m, binPowMod(b, m-2, m) % m, m) % m;
    return res;
}
