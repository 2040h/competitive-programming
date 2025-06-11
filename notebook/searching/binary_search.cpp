// Asumiento que quiero hacer una busqueda binaria en el rango [0, n)
// Importante: chequear el indice porque en caso de que no exista elemento que cumple P(X) puede haber problemas

// Encontrar el indice del elemento v en el array A ordenado
int binarySearch(int start, int end, vector<ll> &A, ll v){
    if (start > end){
        return -1;
    }

    int mid = (start + end)/2;

    if (A[mid] == v){
        return mid;
    } else if (A[mid] < v){
        return binarySearch(mid+1, end, A, v);
    } else {
        return binarySearch(start, mid-1, A, v);
    }
}

// Calcular extremo derecho que cumple P(X)
int rightBinarySearch(int start, int end){
    int l = start - 1;
    int r = end + 1;

    while (r - l > 1){
        int mid = (l + r)/2;

        if (P(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }
    
    if (l < start || l > end || !P(l)) l = -1; // Si l no está en el intervalo [start,end] o no cumple la propiedad, entonces retorno -1
	
    return l; // l es el ultimo elemento que cumple P(X)
}

// Calcular extremo izquierdo que cumple P(X)
int leftBinarySearch(int start, int end){
    int l = start - 1; 
    int r = end + 1; 

    while(r - l > 1) { 
        int mid = (l + r) / 2;
        if(!P(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    if (r < start || r > end || !P(r)) r = -1; // Si r no está en el intervalo [start,end] o no cumple la propiedad, entonces retorno -1

    return r; // r es el primer elemento que cumple P(X)
}


