// ######################################################################
// Input/Output
cout << fixed << setprecision(1); // Imprimir con 1 decimal
cout << setprecision(numeric_limits<long double>::digits10 + 1); // Muestra con full precision para ld

// cin.ignore(numeric_limits<streamsize>::max(), '\n'); Si leimos previamente algo, poner esto antes del getline
string s;
getline(cin, s); // Leer un string con espacios
	
istringstream iss(s);
string word; vector<string> words;
while (iss >> word) words.pb(word); // Leer todas las palabras de un string separado por espacio

// ######################################################################
// String 
string stri = to_string(myInt);
char c; isupper(c); 

// ######################################################################
// Otros
int myint1 = stoi(myString); // Funciona con int y float.
*S.rbegin(); // Elemento más grande de un set
lower_bound(all(A), val); // lower_bound: find the first pos in which val could be inserted without changing the order.
*max_element(all(A)); *min_element(all(A)); // upper_bound: find last postion in which val could be inserted without changing the order.

// Suma de: M[a] + ... + M[b]
int getSumBetween(int a, int b){ // Notar que prefixSum tiene tamaño |M| + 1
    if (a > b || a < 0 || b >= SIZE(prefixSum)-1) return UNDEFINED;
    return prefixSum[b+1] - prefixSum[a];
}

