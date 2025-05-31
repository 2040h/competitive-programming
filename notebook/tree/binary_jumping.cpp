struct BinaryJumping{
	// Estructura para grafos de sucesores.
	vector<vector<int>> binaryJumping;
	int logk;
	
	// Inicializacion en tiempo O(n*log(max_k))
	BinaryJumping(vector<int> &succ, int max_k){
		logk = log2(max_k);  // Piso.
		binaryJumping.assign(SIZE(succ), vector<int>(logk+1, UNDEFINED));
		
		for(int i=0; i<SIZE(succ); i++){
			binaryJumping[i][0] = succ[i];
		}
		
		for(int it=1; it<=logk; it++){
			for(int i=0; i<SIZE(succ); i++){
				if (binaryJumping[i][it-1] != UNDEFINED) binaryJumping[i][it] = binaryJumping[binaryJumping[i][it-1]][it-1];
			}
		}
	}
	
	// O(log(k)). Donde x es el nodo, k es la distancia de salto.
	int succ_k(int x, int k){
		// Suponemos que k >= 0

		int it = 0;
		while(k != 0){
			if ((k & 1) == 1){
				if (x != UNDEFINED) x = binaryJumping[x][it];
			}
			k = k >> 1;
			it++;
		}
		
		return x; // x = UNDEFINED significa que te excediste con los saltos
	}
	
};

// #############################################################################################################
// Implementación alternativa

vector<vector<int>> memoAncestors(SIZE(adjList), vector<int>(log2(SIZE(adjList))+1, UNDEFINED));

void precomputeAncestors(int root, vector<vector<int>> &adjList, vector<vector<int>> &memoAncestors, vector<bool> &visited){
    int k = (int) log2(SIZE(adjList))+1;
    visited[root] = true;

    queue<int> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()){
        int v = toVisit.front();
        toVisit.pop();

        for (int u : adjList[v]){
            if (!visited[u]){
                toVisit.push(u);
                visited[u] = true;
				memo[u][0] = v;
                forsn(i, 1, k){
                    if (memoAncestors[u][i-1] != UNDEFINED){
                        memoAncestors[u][i] = memoAncestors[memoAncestors[u][i-1]][i-1];
                    }
                }
            }
        }
    }
}

int rightBinarySearch(int start, int end, int currentNode, int desiredLevel, vector<vector<int>> &memoAncestors){
    int l = start - 1;
    int r = end + 1;
    
    while (r - l > 1){
        int mid = (l + r)/2;
        int nodeToJump = memoAncestors[currentNode][mid];
 
        if (nodeToJump != UNDEFINED && distanceFromRoot[nodeToJump] >= desiredLevel){
            l = mid;
        } else {
            r = mid;
        }
    }

	if (l < start || l > end || (memoAncestors[currentNode][l] == UNDEFINED)){
		l = UNDEFINED;
	}

 
    return l; // l es el ultimo elemento que cumple P(X)
}

int findTheAncestorFor(int v, int numberOfJumps, vector<vector<int>> &memoAncestors){
    int currentLevel = distanceFromRoot[v];
    int levelToFind = currentLevel - numberOfJumps;
    int currentNode = v;
    int k = SIZE(memoAncestors[0]);
    
	if (levelToFind < 0) return UNDEFINED; // Si te excediste del árbol, indefinite

    while (currentLevel != levelToFind){
        int bestNewLevel = rightBinarySearch(0, k-1, currentNode, levelToFind, memoAncestors);
        currentNode = memoAncestors[currentNode][bestNewLevel];
        currentLevel = distanceFromRoot[currentNode];
    }
 
    return currentNode;
}