int rightBinarySearchForLCA(int start, int end, int v, int w, vector<vector<int>> &memoAncestors){
    int l = start - 1;
    int r = end + 1;
    
    while (r - l > 1){
        int mid = (l + r)/2;
        int nodeToJumpForV = memoAncestors[v][mid];
        int nodeToJumpForW = memoAncestors[w][mid];
 
        if (nodeToJumpForV != UNDEFINED && nodeToJumpForV != nodeToJumpForW){
            l = mid;
        } else {
            r = mid;
        }
    }
    return l; // l es el ultimo elemento que cumple P(X)
}

int findLCA(int v, int w, BinaryJumping &G){
	int jumps = abs(distanceFromRoot[v] - distanceFromRoot[w]);
    if (distanceFromRoot[v] < distanceFromRoot[w]) w = G.succ_k(w, jumps);
    else v = G.succ_k(v, jumps);

    if (v == w) return v;
    int m = G.logk;

    while (G.binaryJumping[v][0] != G.binaryJumping[w][0]){
        int bestNewLevel = rightBinarySearchForLCA(0, m-1, v, w, G.binaryJumping);
        v = G.binaryJumping[v][bestNewLevel];
        w = G.binaryJumping[w][bestNewLevel];
    }

    int lca = G.binaryJumping[v][0];
    return lca;
}