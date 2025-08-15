// Si tengo un conjunto de n elementos
int allEllementsUsed = (1 << (n)) - 1;
int currentElement = 1 << i; // i-esimo elemento indexando en [0, n-1]
int currenBitmask;

if (!(currentBitmask & currentElement)) // Si no estoy usando el i-esimo elemento
currentBitmask |= currentElement; // Ahora lo uso al i-esimo elemento en la bitmask
currenBitmask = currenBitmask & (~currentElement); // Apago el i-esimo elemento de la bitmask

// Ejemplo de uso para DP de contar dominos
// res = dp(0, 0, 0)
ll dp(int i, int j, int k){ // i es la columna actual, j la fila y k la bitmask que describe la columna anterior
	if (i == m && k == 0) return 1; // Si terminé de recorrer las filas y puse cosas válidas en la fila anterior, entonces llegué a una configuración válida
	if (i == m) return 0; // Si terminé de recorrer las filas y puse cosas inválidas en la fila anterior, entonces llegué a una configuración inválida
	if (j == n) return dp(i+1, 0, k); // Si terminé la última fila, ahora me muevo a la siguiente columna
	
	if (memo[i][j][k] == UNDEFINED){
		int a = 1 << j; // Me fijo que bit hay en la fila j en la columna i
		int b = 1 << (j+1); // Me fijo que bit hay en la fila j+1 en la columna i
		
		if (k & a){ // Si estaba prendido el bit j en esta posición quiere decir que comenzaba un bloque horizontal en (i-1, j). Luego, esta posición está ocupada y no puedo hacer nada
			memo[i][j][k] = dp(i, j+1, k & (~a)); // Apago el bit j del vector k y me voy una fila para abajo
		} else { // Había puesto uno vertical, entonces está posición está libre así que tengo dos opciones: uno horizontal o uno vértical
			memo[i][j][k] = dp(i, j+1, k | a); // Pongo uno horizontal y me voy abajo
			// Me fijo si puedo poner uno vértical. Chequeo que el bit j+1 esté apagado
			if (j+1 < n && (k & b) == 0){ //Si está libre el bit en la posición j+1
				memo[i][j][k] = addMod(memo[i][j][k], dp(i, j+2, k));
			}
		}
	}
	
	return memo[i][j][k];
}