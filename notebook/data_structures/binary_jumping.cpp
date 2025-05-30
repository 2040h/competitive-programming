struct BinaryJumping{
	// Estructura para grafos de sucesores.
	vector<vector<int>> binaryJumping;
	int logk;
	
	// Inicializacion en tiempo O(n*log(max_k))
	BinaryJumping(vector<int> &succ, int max_k){
		logk = log2(max_k);  // Piso.
		binaryJumping.assign(SIZE(succ), vector<int>(logk+1));
		
		for(int i=0; i<SIZE(succ); i++){
			binaryJumping[i][0] = succ[i];
		}
		
		for(int it=1; it<=logk; it++){
			for(int i=0; i<SIZE(succ); i++){
				binaryJumping[i][it] = binaryJumping[binaryJumping[i][it-1]][it-1];
			}
		}
	}
	
	// O(log(k)). Donde x es el nodo, k es la distancia de salto.
	int succ_k(int x, int k){
		int it = 0;
		while(k != 0){
			if ((k & 1) == 1){
				x = binaryJumping[x][it];
			}
			k = k >> 1;
			it++;
		}
		
		return x;
	}
	
};
