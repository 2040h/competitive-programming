vector<ll> slidingWindow(vector<ll> &A, int k){
    vector<ll> res;
    ll currentRes = 0;
    forn(i, k) currentRes = f(currentRes, A[i]);
    res.pb(currentRes);
    forsn(i, k, SIZE(A)){
        currentRes = f_inv(currentRes, A[i-k]); // Deshago el valor de elemento que ya no esta mas la ventana
        currentRes = f(currentRes, A[i]);
        res.pb(currentRes);
    }

    return res;
}