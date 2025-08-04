const ll COTA_SUP_N = 110000;
vl lp(COTA_SUP_N+1);
vl primes;

void factorizar(){
	forsn(i, 2, COTA_SUP_N+1){
        if (lp[i] == 0){
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; i*primes[j] <= N && primes[j] != lp[i]; j++) lp[i*primes[j]] = primes[j];
    }
}

