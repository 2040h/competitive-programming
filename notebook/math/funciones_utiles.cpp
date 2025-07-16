vector<int> divisoresOf(int a){
    vector<int> res;
    int until = sqrt(a) + 1;
    forsn(i, 1, until){
        if (a % i == 0) res.pb(i);
        if (a % i == 0 && i != a/i) res.pb(a/i);
    }

    return res;
}

int sumDigits(int m) {
    int sum = 0;
    while (m > 0) {
        sum += m % 10;
        m /= 10;      
    }
    return sum;
}

// Factorizar un número n, cuesta calcular la # de primos <= sqrt(n)
// Hay que llamar a la criba de eratostenes antes (con la cota correcta de primos calculados)
vector<pair<ll, int>> factorizar_primos(ll a){
    vector<pair<ll, int>> factorizacion_primos;
    for (ll p : primes){
		int potencia = 0;
		if (a == 1) break;
		
		while (a % p == 0){
			a /= p;
			potencia++;
		}
		
		if (potencia > 0) factorizacion_primos.pb({p, potencia});
	}
        
    if (a != 1) factorizacion_primos.pb({a, 1}); // Si no es 1 después de haberlo dividido por los primos de hasta sqrt(a), entonces es un primo > sqrt(a) de potencia 1
    return factorizacion_primos;
}
